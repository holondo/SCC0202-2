all: main auxiliar colecao avl abb lo lp lu
	gcc -Wall -g build/main.o build/auxiliar.o build/colecao.o build/avl.o build/abb.o build/lo.o build/lp.o build/lu.o -o build/main
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
lo: lo.c
	gcc -Wall -g lo.c -c -o build/lo.o
lp: lp.c
	gcc -Wall -g lp.c -c -o build/lp.o
lu: lu.c
	gcc -Wall -g lu.c -c -o build/lu.o
run:
	./main
clean:
	rm build/*