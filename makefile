c := "lab.c"
py := "lab.py"

start:
	python3  ${py} 
	gcc ${c} -o xport
	./xport < entradas.txt


	
