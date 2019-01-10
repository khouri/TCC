FILE = main

all :
	echo "Compilando"
	pdflatex -shell-escape $(FILE).tex
	bibtex $(FILE).aux
	pdflatex -shell-escape $(FILE).tex
	pdflatex -shell-escape $(FILE).tex
	evince main.pdf
	rm *.bbl *.blg *.aux *log *.brf

clean:
	echo "Limpando arquivos auxiliares"
	rm *.bbl *.blg *.aux *log *.brf
