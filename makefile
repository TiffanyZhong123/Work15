all: work15.o
	gcc -o test work15.o

forking.o: work15.c
	gcc -c work15.c

run:
	./test

clean:
	rm out
	rm *.o
