import os
import re
import time
import requests
from bs4 import BeautifulSoup

# Configurações
DIRETORIO_CSES = "." 
DIRETORIO_ENUNCIADOS = "Enunciados"
ARQUIVO_SAIDA = "caderno_cses.tex"

def normalizar_nome(texto):
    return re.sub(r'[^a-zA-Z0-9]', '', texto).lower()

def escapar_latex(texto):
    caracteres = {
        '%': '\\%',
        '#': '\\#',
        '_': '\\_',
        '&': '\\&',
        '$': '\\$', 
    }
    for char, escaped in caracteres.items():
        texto = texto.replace(char, escaped)
    return texto

print("Obtendo lista de problemas do site CSES...")
try:
    resposta = requests.get("https://cses.fi/problemset/", timeout=15)
    soup = BeautifulSoup(resposta.text, 'html.parser')
except requests.exceptions.RequestException:
    print("Erro fatal: Não foi possível acessar a página inicial do CSES. Verifique sua internet.")
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
    r"\usepackage{listings}",
    r"\usepackage{xcolor}",
    r"\usepackage[margin=1.5cm]{geometry}",
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
    r"    breaklines=true,",
    r"    tabsize=4",
    r"}",
    r"",
    r"\begin{document}",
    r"\tableofcontents",
    r"\newpage"
]

# Percorre as pastas no diretório local
for nome_pasta in sorted(os.listdir(DIRETORIO_CSES)):
    caminho_pasta = os.path.join(DIRETORIO_CSES, nome_pasta)
    
    # Ignora arquivos soltos, pastas ocultas e a própria pasta de Enunciados
    if not os.path.isdir(caminho_pasta) or nome_pasta.startswith('.') or nome_pasta in ['__pycache__', DIRETORIO_ENUNCIADOS]:
        continue
        
    titulo_capitulo = re.sub(r'([a-z])([A-Z])', r'\1 \2', nome_pasta)
    latex.append(f"\n\\chapter{{{titulo_capitulo}}}")
    
    # Cria a subpasta equivalente dentro de "Enunciados"
    pasta_destino_enunciado = os.path.join(DIRETORIO_ENUNCIADOS, nome_pasta)
    os.makedirs(pasta_destino_enunciado, exist_ok=True)
    
    print(f"\nLendo diretório: {nome_pasta}")
    
    for nome_arquivo in sorted(os.listdir(caminho_pasta)):
        if nome_arquivo.endswith(".cpp"):
            nome_base = nome_arquivo[:-4]
            nome_normalizado = normalizar_nome(nome_base)
            titulo_exibicao = re.sub(r'([a-z])([A-Z])', r'\1 \2', nome_base)
            
            caminho_arquivo_enunciado = os.path.join(pasta_destino_enunciado, f"{nome_base}.tex")
            
            latex.append(f"\n\\section{{{titulo_exibicao}}}")
            
            # Verifica se o enunciado já foi baixado antes (Cache)
            if os.path.exists(caminho_arquivo_enunciado):
                print(f"  [Cache] Lendo enunciado salvo: {titulo_exibicao}")
                caminho_latex_enunciado = caminho_arquivo_enunciado.replace('\\', '/')
                latex.append(f"\\input{{{caminho_latex_enunciado}}}")
                
            # Se não existir, baixa do site
            elif nome_normalizado in mapa_problemas:
                dados = mapa_problemas[nome_normalizado]
                titulo_exibicao = dados['titulo']
                
                print(f"  [Download] Baixando enunciado: {titulo_exibicao}...")
                
                try:
                    pagina_prob = requests.get(dados['url'], timeout=10)
                    soup_prob = BeautifulSoup(pagina_prob.text, 'html.parser')
                    
                    div_conteudo = soup_prob.find('div', class_='content')
                    if div_conteudo:
                        paragrafos = div_conteudo.find_all('p', recursive=False)
                        texto_extraido = "\n\n".join([p.text for p in paragrafos])
                        enunciado_escapado = escapar_latex(texto_extraido)
                        
                        # Salva no arquivo separado (.tex)
                        with open(caminho_arquivo_enunciado, 'w', encoding='utf-8') as f_enunc:
                            f_enunc.write(enunciado_escapado)
                        
                        # Adiciona o comando \input no LaTeX principal
                        caminho_latex_enunciado = caminho_arquivo_enunciado.replace('\\', '/')
                        latex.append(f"\\input{{{caminho_latex_enunciado}}}")
                        
                    time.sleep(0.5) 
                    
                except requests.exceptions.RequestException:
                    print(f"    [!] Falha de conexão. Arquivo não salvo.")
                    latex.append("Erro: O download deste enunciado falhou devido a problemas de rede.")
            else:
                latex.append("Enunciado não encontrado no site.")

            # Injeta o código C++
            latex.append(r"\vspace{0.3cm}")
            latex.append(r"\textbf{Código-fonte:}")
            caminho_relativo_cpp = f"{nome_pasta}/{nome_arquivo}"
            latex.append(f"\\lstinputlisting{{{caminho_relativo_cpp}}}")

latex.append(r"\end{document}")

with open(ARQUIVO_SAIDA, 'w', encoding='utf-8') as f:
    f.write("\n".join(latex))

print(f"\nConcluído! Arquivo '{ARQUIVO_SAIDA}' e pasta '{DIRETORIO_ENUNCIADOS}' gerados com sucesso.")