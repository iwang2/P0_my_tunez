all: list.o main.o
	gcc -o things list.o main.o

list.o: list.c list.h
	gcc -c list.c

main.o: main.c list.h
	gcc -c main.c

clean:
	rm things
	rm *.o
	rm *~

run: all
	./things
