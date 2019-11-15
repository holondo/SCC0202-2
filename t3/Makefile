all: main
# compilacao do executável em si, com todos os objetos gerados
main: main.c 
	gcc -Wall -o build/main -g main.c 
# execução do objeto previamente compilado
colecao: colecao.h
	gcc -Wall -o build/colecao.o -g colecao.h colecao.c
run:
	build/main 