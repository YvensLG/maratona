# Nomes dos arquivos
SCRIPT = gerador_cses.py
TEX_FILE = caderno_cses.tex
PDF_FILE = caderno_cses.pdf

# Avisa o Make que essas palavras não são nomes de arquivos
.PHONY: all caderno clean

# Ação padrão se você digitar apenas "make"
all: caderno

# Comando principal: make caderno
caderno:
	@echo "==> Rodando o script Python (baixando enunciados)..."
	python3 $(SCRIPT)
	@echo "==> Compilando o LaTeX (Passo 1/2)..."
	pdflatex -interaction=nonstopmode $(TEX_FILE) > /dev/null
	@echo "==> Compilando o LaTeX (Passo 2/2 para o sumário)..."
	pdflatex -interaction=nonstopmode $(TEX_FILE) > /dev/null
	@echo "==> Sucesso! $(PDF_FILE) gerado."

# Comando extra: make clean (para limpar o lixo do LaTeX)
clean:
	@echo "==> Limpando arquivos auxiliares..."
	rm -f *.aux *.log *.toc *.out $(TEX_FILE)