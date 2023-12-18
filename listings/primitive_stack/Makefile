CC=g++
CFLAGS=-I.
build: main.o stack.o
	$(CC) -o stack main.o stack.o

debug: main.cpp stack.cpp
	$(CC) -g -o stack main.cpp stack.cpp

clean:
	rm *.o *.out stack
