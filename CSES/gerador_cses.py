import os
import re
import time
import requests
from bs4 import BeautifulSoup

# --- CONFIGURAÇÕES ---
DIRETORIO_CSES = "src" 
DIRETORIO_ENUNCIADOS = "enunciados"
ARQUIVO_SAIDA = "latex/caderno_cses.tex"

HEADERS = {
    'User-Agent': 'Mozilla/5.0 (Windows NT 10.0; Win64; x64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/120.0.0.0 Safari/537.36'
}

def normalizar_nome(texto):
    return re.sub(r'[^a-zA-Z0-9]', '', texto).lower()

def escapar_latex(texto):
    texto = texto.replace('\\%', '%').replace('\\#', '#').replace('\\&', '&')
    caracteres = {'%': '\\%', '#': '\\#', '&': '\\&'}
    for char, escaped in caracteres.items():
        texto = texto.replace(char, escaped)
    texto = texto.replace('<', '$<$').replace('>', '$>$')
    return texto

def limpar_codigo_cpp(caminho_original, caminho_novo):
    with open(caminho_original, 'r', encoding='utf-8') as f:
        texto = f.read()
    
    linhas = texto.split('\n')
    linhas_limpas = []
    for linha in linhas:
        stripped = linha.strip()
        if stripped.startswith('#include'): continue
        if stripped.startswith('#define'): continue
        if stripped.startswith('typedef'): continue
        if stripped.startswith('using namespace'): continue
        if stripped.startswith('#pragma'): continue
        if 'ios_base::sync_with_stdio' in stripped: continue
        if 'cin.tie' in stripped: continue
        linhas_limpas.append(linha.rstrip())
        
    texto = '\n'.join(linhas_limpas)
    
    match = re.search(r"(?:int|int32_t|signed)\s+main\s*\(\s*\)\s*\{", texto)
    if match:
        start_idx = match.start()
        body_start = match.end()
        
        open_braces = 1
        end_idx = -1
        for i in range(body_start, len(texto)):
            if texto[i] == '{':
                open_braces += 1
            elif texto[i] == '}':
                open_braces -= 1
                if open_braces == 0:
                    end_idx = i
                    break
                    
        if end_idx != -1:
            miolo = texto[body_start:end_idx]
            miolo_limpo = re.sub(r'//.*', '', miolo) 
            miolo_limpo = re.sub(r'int\s+t\s*;\s*cin\s*>>\s*t\s*;\s*(?:for|while)\s*\([^)]+\)', '', miolo_limpo)
            miolo_limpo = re.sub(r'solve\(\)\s*;', '', miolo_limpo) 
            miolo_limpo = re.sub(r'return\s+0\s*;', '', miolo_limpo) 
            # --- NOVO: Remove a macro de fast I/O isolada (com ou sem ponto e vírgula) ---
            miolo_limpo = re.sub(r'\b_\b\s*;?', '', miolo_limpo) 
            miolo_limpo = miolo_limpo.replace('{', '').replace('}', '') 
            
            if miolo_limpo.strip() == "":
                texto = texto[:start_idx] + texto[end_idx+1:]
    
    texto = re.sub(r'\n{3,}', '\n\n', texto).strip()
    
    os.makedirs(os.path.dirname(caminho_novo), exist_ok=True)
    with open(caminho_novo, 'w', encoding='utf-8') as f:
        f.write(texto + '\n')

print("Obtendo lista de problemas do site CSES...")
try:
    resposta = requests.get("https://cses.fi/problemset/", headers=HEADERS, timeout=15)
    soup = BeautifulSoup(resposta.text, 'html.parser')
except requests.exceptions.RequestException:
    print("Erro fatal: Não foi possível acessar a página inicial do CSES.")
    exit(1)

mapa_problemas = {}
for lista_tarefas in soup.find_all('ul', class_='task-list'):
    for link in lista_tarefas.find_all('a'):
        titulo = link.text.strip()
        url = "https://cses.fi" + link['href']
        mapa_problemas[normalizar_nome(titulo)] = {'titulo': titulo, 'url': url}

ORDEM_CSES = [
    "IntroductoryProblems",
    "SortingandSearching",
    "DynamicProgramming",
    "GraphAlgorithms",
    "RangeQueries",
    "TreeAlgorithms",
    "Mathematics",
    "StringAlgorithms",
    "AdvancedTechniques",
    "AdditionalProblemsI",
    "AdditionalProblemsII",
    "AdvancedGraphProblems",
    "BitwiseOperations",
    "ConstructionProblems",
    "CountingProblems",
    "SlidingWindowProblems"
]

def obter_ordem(nome):
    try:
        return ORDEM_CSES.index(nome)
    except ValueError:
        return 999 

latex = [
    r"\documentclass[8pt]{extarticle}",
    r"\usepackage[utf8]{inputenc}",
    r"\usepackage[T1]{fontenc}",
    r"\usepackage{amsmath, amssymb}",
    r"\usepackage{graphicx}",
    r"\usepackage{listings}",
    r"\usepackage{xcolor}",
    r"\usepackage[a4paper, landscape, left=1cm, right=1cm, top=1.5cm, bottom=1cm, headheight=15pt]{geometry}",
    r"\usepackage{multicol}",
    r"\usepackage{tocloft}",
    r"\usepackage[many]{tcolorbox}",
    r"\usepackage{fancyhdr}",
    r"\pagestyle{fancy}",
    r"\fancyhf{}", 
    r"\fancyhead[L]{\textbf{CSES Problem Set - UNICAMP}}", 
    r"\fancyhead[R]{\textbf{Página \thepage}}",            
    r"\renewcommand{\headrulewidth}{0.4pt}",               
    r"\renewcommand{\footrulewidth}{0pt}",
    
    r"\fancypagestyle{plain}{",
    r"    \fancyhf{}",
    r"    \fancyhead[L]{\textbf{CSES Problem Set - UNICAMP}}",
    r"    \fancyhead[R]{\textbf{Página \thepage}}",
    r"    \renewcommand{\headrulewidth}{0.4pt}",
    r"}",
    r"\addtolength{\cftsecnumwidth}{0.5em}",      
    r"\addtolength{\cftsubsecnumwidth}{1.2em}",   
    r"\setlength{\columnseprule}{0.4pt}", 
    r"\setlength{\columnsep}{25pt}",      
    r"",
    r"\newtcolorbox{caixaenunciado}{",
    r"    colback=gray!5,",
    r"    colframe=gray!40,",
    r"    arc=2pt,",
    r"    boxrule=0.5pt,",
    r"    left=4pt, right=4pt, top=4pt, bottom=4pt,",
    r"    breakable,",
    r"    before skip=0.2cm, after skip=0.2cm",
    r"}",
    r"",
    r"\lstset{",
    r"    language=C++,",
    r"    basicstyle=\ttfamily\footnotesize,", 
    r"    keywordstyle=\color{blue},",
    r"    commentstyle=\color{green!50!black},",
    r"    stringstyle=\color{red},",
    r"    numbers=left,",
    r"    numberstyle=\tiny,",
    r"    numbersep=5pt,",                 
    r"    stepnumber=1,",
    r"    xleftmargin=2.0em,",             
    r"    framexleftmargin=2.0em,",
    r"    breaklines=true,",
    r"    tabsize=4,",
    r"    extendedchars=true,",
    r"    literate={á}{{\'a}}1 {ã}{{\~a}}1 {é}{{\'e}}1 {í}{{\'i}}1 {ó}{{\'o}}1 {õ}{{\~o}}1 {ú}{{\'u}}1 {ç}{{\c{c}}}1 {Á}{{\'A}}1 {É}{{\'E}}1 {Í}{{\'I}}1 {Ó}{{\'O}}1 {Ú}{{\'U}}1 {Ç}{{\c{C}}}1 {Ã}{{\~A}}1 {Õ}{{\~O}}1",
    r"}",
    r"",
    r"\usepackage[hidelinks]{hyperref}", # <-- PACOTE MÁGICO ADICIONADO AQUI
    r"",
    r"\begin{document}",
    r"\raggedbottom",
    r"\begin{titlepage}",
    r"    \centering",
    r"    \vspace*{1.5cm}",
    r"    \includegraphics[width=4.5cm]{../assets/unicamp.png} \par", 
    r"    \vspace{0.4cm}",
    r"    {\fontsize{16}{20}\selectfont Universidade Estadual de Campinas \par}",
    r"    \vspace{1.2cm}",
    r"    {\fontsize{42}{50}\selectfont Enemy Leo used Appeal! It's \par}",
    r"    \vspace{0.2cm}",
    r"    {\fontsize{42}{50}\selectfont super effective! Pikachu fainted! \par}",
    r"    \vspace{1.5cm}",
    r"    {\fontsize{20}{24}\selectfont \textbf{CSES Problem Set} \par}",
    r"    \vspace{1cm}",
    r"    {\fontsize{14}{18}\selectfont Pedro Assunção, Pedro Ferreira, Yvens Porto \par}",
    r"    \vfill",
    r"    {\fontsize{12}{14}\selectfont 2026-08-18 \par}",
    r"\end{titlepage}",
    
    r"\begin{multicols*}{3}",
    r"\tableofcontents",
    r"\end{multicols*}",         
    r"\pagebreak",               
    r"\begin{multicols*}{3}", 
]

try:
    os.makedirs(os.path.dirname(ARQUIVO_SAIDA), exist_ok=True)
    pastas_locais = os.listdir(DIRETORIO_CSES)
    pastas_ordenadas = sorted(pastas_locais, key=lambda x: (obter_ordem(x), x))

    primeira_secao = True

    for nome_pasta in pastas_ordenadas:
        caminho_pasta = os.path.join(DIRETORIO_CSES, nome_pasta)
        
        if not os.path.isdir(caminho_pasta) or nome_pasta.startswith('.') or nome_pasta in ['__pycache__']:
            continue
        
        if not primeira_secao:
            latex.append(r"\end{multicols*}")
            latex.append(r"\pagebreak")
            latex.append(r"\begin{multicols*}{3}")
        primeira_secao = False
            
        titulo_capitulo = re.sub(r'([a-z])([A-Z])', r'\1 \2', nome_pasta)
        latex.append(f"\n\\section{{{titulo_capitulo}}}") 
        
        pasta_destino_enunciado = os.path.join(DIRETORIO_ENUNCIADOS, nome_pasta)
        os.makedirs(pasta_destino_enunciado, exist_ok=True)
        
        print(f"\nLendo diretório: {nome_pasta}")
        
        for nome_arquivo in sorted(os.listdir(caminho_pasta)):
            if nome_arquivo.endswith(".cpp"):
                nome_base = nome_arquivo[:-4]
                nome_normalizado = normalizar_nome(nome_base)
                
                titulo_bruto = re.sub(r'([a-z])([A-Z])', r'\1 \2', nome_base)
                titulo_exibicao = escapar_latex(titulo_bruto).replace('_', '\\_') 
                
                caminho_arquivo_enunciado = os.path.join(pasta_destino_enunciado, f"{nome_base}.tex")
                
                latex.append(f"\n\\subsection{{{titulo_exibicao}}}") 
                
                if os.path.exists(caminho_arquivo_enunciado) and os.path.getsize(caminho_arquivo_enunciado) > 0:
                    print(f"  [Cache] Lendo enunciado salvo: {titulo_bruto}")
                    caminho_latex_enunciado = caminho_arquivo_enunciado.replace('\\', '/')
                    latex.append(r"\begin{caixaenunciado}")
                    latex.append(f"\\input{{../{caminho_latex_enunciado}}}")
                    latex.append(r"\end{caixaenunciado}")
                    
                elif nome_normalizado in mapa_problemas:
                    dados = mapa_problemas[nome_normalizado]
                    titulo_site = dados['titulo']
                    
                    print(f"  [Download] Baixando enunciado: {titulo_site}...")
                    
                    try:
                        pagina_prob = requests.get(dados['url'], headers=HEADERS, timeout=10)
                        if pagina_prob.status_code != 200:
                            print(f"    [!] BLOQUEADO: HTTP {pagina_prob.status_code}.")
                            latex.append(f"Erro: Download falhou (HTTP {pagina_prob.status_code}).")
                            time.sleep(1.5)
                            continue

                        soup_prob = BeautifulSoup(pagina_prob.text, 'html.parser')
                        div_conteudo = soup_prob.find('div', class_='content')
                        
                        if div_conteudo:
                            for header in div_conteudo.find_all(['h1', 'h2', 'h3', 'h4', 'b', 'strong']):
                                texto_header = header.get_text().lower()
                                if 'example' in texto_header or 'exemplo' in texto_header:
                                    curr = header
                                    while curr:
                                        nxt = curr.next_sibling
                                        curr.extract()
                                        curr = nxt
                                    break
                            
                            for math_span in div_conteudo.find_all('span', class_='math'):
                                delimiter = "$$" if 'display' in math_span.get('class', []) else "$"
                                math_span.replace_with(soup_prob.new_string(f"{delimiter}{math_span.get_text()}{delimiter}"))
                            
                            for header in div_conteudo.find_all(['h1', 'h2', 'h3']):
                                txt = header.get_text().strip()
                                header.replace_with(soup_prob.new_string(f"\n\n\\vspace{{0.3cm}}\\noindent\\textbf{{{txt}}}\n\n"))
                                
                            for ul in div_conteudo.find_all('ul'):
                                if 'task-constraints' in ul.get('class', []):
                                    ul.extract()
                                    continue
                                itens = [f"\\textbullet\\ {li.get_text().strip()}" for li in ul.find_all('li')]
                                ul.replace_with(soup_prob.new_string("\n\n" + "\n".join(itens) + "\n\n"))
                                
                            texto_extraido = div_conteudo.get_text()
                            texto_extraido = re.sub(r'\n{3,}', '\n\n', texto_extraido).strip()
                            
                            if texto_extraido:
                                enunciado_escapado = escapar_latex(texto_extraido)
                                with open(caminho_arquivo_enunciado, 'w', encoding='utf-8') as f_enunc:
                                    f_enunc.write(enunciado_escapado)
                                    
                                caminho_latex_enunciado = caminho_arquivo_enunciado.replace('\\', '/')
                                latex.append(r"\begin{caixaenunciado}")
                                latex.append(f"\\input{{../{caminho_latex_enunciado}}}")
                                latex.append(r"\end{caixaenunciado}")
                            else:
                                latex.append("Texto indisponível.")
                        else:
                            latex.append("Conteúdo não localizado.")
                            
                        time.sleep(1.0) 
                        
                    except requests.exceptions.RequestException:
                        latex.append("Erro de rede.")
                else:
                    latex.append("Enunciado não encontrado no site.")

                latex.append(r"\vspace{0.3cm}")
                # latex.append(r"\noindent\textbf{Código-fonte:}")
                
                # --- A MÁGICA ACONTECE AQUI ---
                caminho_original_cpp = f"{DIRETORIO_CSES}/{nome_pasta}/{nome_arquivo}"
                caminho_cpp_limpo = f"latex/src_limpo/{nome_pasta}/{nome_arquivo}"
                
                limpar_codigo_cpp(caminho_original_cpp, caminho_cpp_limpo)
                
                # O LaTeX lê o código limpo ao invés do original
                latex.append(f"\\lstinputlisting{{src_limpo/{nome_pasta}/{nome_arquivo}}}")

except KeyboardInterrupt:
    print("\n\n[!] Interrompido (Ctrl+C)!")

finally:
    latex.append(r"\end{multicols*}")
    latex.append(r"\end{document}")
    with open(ARQUIVO_SAIDA, 'w', encoding='utf-8') as f:
        f.write("\n".join(latex))
    print(f"\nPronto! Arquivo '{ARQUIVO_SAIDA}' gerado e salvo na pasta latex.")