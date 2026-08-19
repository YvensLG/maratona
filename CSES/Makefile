caderno:
	@echo "==> Preparando as pastas..."
	@mkdir -p latex
	@echo "==> Rodando o script Python..."
	@python3 gerador_cses.py
	@echo "==> Compilando o LaTeX (Passo 1/2)..."
	@cd latex && pdflatex -interaction=nonstopmode caderno_cses.tex > /dev/null
	@echo "==> Compilando o LaTeX (Passo 2/2)..."
	@cd latex && pdflatex -interaction=nonstopmode caderno_cses.tex > /dev/null
	@echo "==> Trazendo o PDF para a raiz..."
	@mv latex/caderno_cses.pdf .
	@echo "Pronto! 'caderno_cses.pdf' gerado com sucesso."

clean:
	@echo "==> Limpando os arquivos de compilação..."
	@rm -rf latex caderno_cses.pdf