SET main=tesi
@echo off
cls
echo PDFLATEX --- 1/5
pdflatex   %main%.tex 
echo BIBTEX --- 2/5
bibtex  %main% >> BIBOUT
echo PDFLATEX --- 3/5
pdflatex  %main%.tex
echo PDFLATEX --- 4/5
pdflatex  %main%.tex
echo PDFLATEX --- 5/5
pdflatex  %main%.tex
echo DONE --- OPENING PDF 1/1
START "" %main%.pdf
clean.bat