import os
import re
import time
import requests
from bs4 import BeautifulSoup

# Configurações
DIRETORIO_CSES = "." 
DIRETORIO_ENUNCIADOS = "Enunciados"
ARQUIVO_SAIDA = "caderno_cses.tex"

HEADERS = {
    'User-Agent': 'Mozilla/5.0 (Windows NT 10.0; Win64; x64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/120.0.0.0 Safari/537.36'
}

def normalizar_nome(texto):
    return re.sub(r'[^a-zA-Z0-9]', '', texto).lower()

def escapar_latex(texto):
    # Previne escape duplo
    texto = texto.replace('\\%', '%').replace('\\#', '#').replace('\\&', '&')
    caracteres = {'%': '\\%', '#': '\\#', '&': '\\&'}
    for char, escaped in caracteres.items():
        texto = texto.replace(char, escaped)
    texto = texto.replace('<', '$<$').replace('>', '$>$')
    return texto

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

latex = [
    r"\documentclass[a4paper,10pt,twocolumn]{report}",
    r"\usepackage[utf8]{inputenc}",
    r"\usepackage[T1]{fontenc}",
    r"\usepackage{amsmath, amssymb}",
    r"\usepackage{listings}",
    r"\usepackage{xcolor}",
    r"\usepackage[margin=1.5cm]{geometry}",
    r"\setlength{\columnseprule}{0.4pt}",  # <-- Linha vertical separando as colunas
    r"\setlength{\columnsep}{20pt}",       # <-- Mais espaço para o texto respirar
    r"",
    r"\lstset{",
    r"    language=C++,",
    r"    basicstyle=\ttfamily\scriptsize,",
    r"    keywordstyle=\color{blue},",
    r"    commentstyle=\color{green!50!black},",
    r"    stringstyle=\color{red},",
    r"    numbers=left,",
    r"    numberstyle=\tiny,",
    r"    stepnumber=1,",
    r"    xleftmargin=1.8em,",            # <-- Impede que os números da linha invadam o texto
    r"    framexleftmargin=1.5em,",
    r"    breaklines=true,",
    r"    tabsize=4,",
    r"    extendedchars=true,",
    r"    literate={á}{{\'a}}1 {ã}{{\~a}}1 {é}{{\'e}}1 {í}{{\'i}}1 {ó}{{\'o}}1 {õ}{{\~o}}1 {ú}{{\'u}}1 {ç}{{\c{c}}}1 {Á}{{\'A}}1 {É}{{\'E}}1 {Í}{{\'I}}1 {Ó}{{\'O}}1 {Ú}{{\'U}}1 {Ç}{{\c{C}}}1 {Ã}{{\~A}}1 {Õ}{{\~O}}1",
    r"}",
    r"",
    r"\begin{document}",
    r"\tableofcontents",
    r"\newpage"
]

try:
    for nome_pasta in sorted(os.listdir(DIRETORIO_CSES)):
        caminho_pasta = os.path.join(DIRETORIO_CSES, nome_pasta)
        
        if not os.path.isdir(caminho_pasta) or nome_pasta.startswith('.') or nome_pasta in ['__pycache__', DIRETORIO_ENUNCIADOS]:
            continue
            
        titulo_capitulo = re.sub(r'([a-z])([A-Z])', r'\1 \2', nome_pasta)
        latex.append(f"\n\\chapter{{{titulo_capitulo}}}")
        
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
                
                latex.append(f"\n\\section{{{titulo_exibicao}}}")
                
                if os.path.exists(caminho_arquivo_enunciado) and os.path.getsize(caminho_arquivo_enunciado) > 0:
                    print(f"  [Cache] Lendo enunciado salvo: {titulo_bruto}")
                    caminho_latex_enunciado = caminho_arquivo_enunciado.replace('\\', '/')
                    latex.append(f"\\input{{{caminho_latex_enunciado}}}")
                    
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
                            # 1. ARRANCAR OS EXEMPLOS PELA RAIZ DO HTML
                            for header in div_conteudo.find_all(['h1', 'h2', 'h3', 'h4', 'b', 'strong']):
                                texto_header = header.get_text().lower()
                                if 'example' in texto_header or 'exemplo' in texto_header:
                                    curr = header
                                    # Poda a partir do Example até o fim do div
                                    while curr:
                                        nxt = curr.next_sibling
                                        curr.extract()
                                        curr = nxt
                                    break
                            
                            # 2. Proteger a Matemática
                            for math_span in div_conteudo.find_all('span', class_='math'):
                                delimiter = "$$" if 'display' in math_span.get('class', []) else "$"
                                math_span.replace_with(soup_prob.new_string(f"{delimiter}{math_span.get_text()}{delimiter}"))
                            
                            # 3. Formatar Títulos (Input/Output/Constraints) com espaços no LaTeX
                            for header in div_conteudo.find_all(['h1', 'h2', 'h3']):
                                txt = header.get_text().strip()
                                header.replace_with(soup_prob.new_string(f"\n\n\\vspace{{0.3cm}}\\noindent\\textbf{{{txt}}}\n\n"))
                                
                            # 4. Formatar Listas em Bullet Points
                            for ul in div_conteudo.find_all('ul'):
                                if 'task-constraints' in ul.get('class', []):
                                    ul.extract()
                                    continue
                                itens = [f"\\textbullet\\ {li.get_text().strip()}" for li in ul.find_all('li')]
                                ul.replace_with(soup_prob.new_string("\n\n" + "\n".join(itens) + "\n\n"))
                                
                            texto_extraido = div_conteudo.get_text()
                            # Garante que os parágrafos tenham uma quebra dupla (exigência do LaTeX)
                            texto_extraido = re.sub(r'\n{3,}', '\n\n', texto_extraido).strip()
                            
                            if texto_extraido:
                                enunciado_escapado = escapar_latex(texto_extraido)
                                with open(caminho_arquivo_enunciado, 'w', encoding='utf-8') as f_enunc:
                                    f_enunc.write(enunciado_escapado)
                                    
                                caminho_latex_enunciado = caminho_arquivo_enunciado.replace('\\', '/')
                                latex.append(f"\\input{{{caminho_latex_enunciado}}}")
                            else:
                                latex.append("Texto indisponível.")
                        else:
                            latex.append("Conteúdo não localizado.")
                            
                        time.sleep(1.0) 
                        
                    except requests.exceptions.RequestException:
                        latex.append("Erro de rede.")
                else:
                    latex.append("Enunciado não encontrado no site.")

                # Inserindo o código-fonte perfeitamente alinhado
                latex.append(r"\vspace{0.3cm}")
                latex.append(r"\noindent\textbf{Código-fonte:}")
                caminho_relativo_cpp = f"{nome_pasta}/{nome_arquivo}"
                latex.append(f"\\lstinputlisting{{{caminho_relativo_cpp}}}")

except KeyboardInterrupt:
    print("\n\n[!] Interrompido (Ctrl+C)!")

finally:
    latex.append(r"\end{document}")
    with open(ARQUIVO_SAIDA, 'w', encoding='utf-8') as f:
        f.write("\n".join(latex))
    print(f"\nPronto! Arquivo '{ARQUIVO_SAIDA}' gerado e salvo.")