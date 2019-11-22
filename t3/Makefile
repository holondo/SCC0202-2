all: main auxiliar colecao avl abb li
	gcc -Wall -g build/main.o build/auxiliar.o build/colecao.o build/avl.o build/abb.o build/li.o -lm -o build/main
main: main.c
	gcc -Wall -g main.c -c -o build/main.o 
auxiliar: auxiliar.c
	gcc -Wall -g auxiliar.c -c -o build/auxiliar.o
colecao: colecao.c
	gcc -Wall -g colecao.c -c -o build/colecao.o
avl: avl.c
	gcc -Wall -g avl.c -c -o build/avl.o
abb: abb.c
	gcc -Wall -g abb.c -c -o build/abb.o
li: li.c
	gcc -Wall -g li.c -c -o build/li.o
run:
	build/main
clean:
	rm build/*