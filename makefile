c := "./src/lab.c"
py := "./src/lab.py"

start:
	python3 ${py} 
	gcc ${c} -o xport
	./xport < entradas.txt


	
