all:
	gcc -c -O2 heap.c
	gcc -c -O2 bst.c 
	gcc -c -O2 fits.c
	gcc -c -O2 sort.c
	gcc -O2 -Wall heap.o bst.o fits.o sort.o main.c -o trab2

run:
	./trab2 in/5.txt
	./trab2 in/20.txt
	./trab2 in/100.txt
	./trab2 in/1000.txt
	./trab2 in/10000.txt
	./trab2 in/100000.txt 
	./trab2 in/1000000.txt 

clean : 
	rm -rf *.o
