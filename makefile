c := "lab.c"
py := "lab.py"

start:
	gcc ${c} -o exec
	./exec < entradas.txt

desenho: 
	python3  ${py} 
