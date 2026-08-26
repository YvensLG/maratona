caderno:
	@echo "==> Preparando as pastas..."
	@mkdir -p latex
	@echo "==> Rodando o script Python..."
	@python3 gerador_cses.py
	@echo "==> Compilando o LaTeX (Passo 1/3)..."
	@cd latex && pdflatex -interaction=nonstopmode caderno_cses.tex > /dev/null || true
	@echo "==> Compilando o LaTeX (Passo 2/3)..."
	@cd latex && pdflatex -interaction=nonstopmode caderno_cses.tex > /dev/null || true
	@echo "==> Compilando o LaTeX (Passo 3/3)..."
	@cd latex && pdflatex -interaction=nonstopmode caderno_cses.tex > /dev/null || true
	@echo "==> Trazendo o PDF para a raiz..."
	@cp latex/caderno_cses.pdf . 2>/dev/null || echo "Falha ao copiar o PDF."
	@echo "Pronto! 'caderno_cses.pdf' gerado com sucesso."

clean:
	@echo "==> Limpando os arquivos de compilação..."
	rm -f *.aux *.toc *.log *.out *.pdf
	rm -f latex/*.aux latex/*.toc latex/*.log latex/*.out latex/*.lol latex/*.pdf