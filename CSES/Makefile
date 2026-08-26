caderno:
	@echo "==> Preparando as pastas..."
	@mkdir -p latex
	@echo "==> Rodando o script Python..."
	@python3 gerador_cses.py
	@echo "==> Compilando o LaTeX (Passo 1/3)..."
	@cd latex && pdflatex -jobname=build_caderno -interaction=nonstopmode caderno_cses.tex > /dev/null
	@echo "==> Compilando o LaTeX (Passo 2/3)..."
	@cd latex && pdflatex -jobname=build_caderno -interaction=nonstopmode caderno_cses.tex > /dev/null
	@echo "==> Compilando o LaTeX (Passo 3/3)..."
	@cd latex && pdflatex -jobname=build_caderno -interaction=nonstopmode caderno_cses.tex > /dev/null
	@echo "==> Trazendo o PDF para a raiz..."
	@mv latex/build_caderno.pdf ./caderno_cses.pdf
	@echo "Pronto! 'caderno_cses.pdf' gerado com sucesso."

clean:
	@echo "==> Limpando os arquivos de compilação..."
	rm -f *.aux *.toc *.log *.out *.pdf
	rm -f latex/*.aux latex/*.toc latex/*.log latex/*.out latex/*.lol latex/*.pdf latex/build_caderno.*