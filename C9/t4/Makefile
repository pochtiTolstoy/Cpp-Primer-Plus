CC=g++
CFLAGS=-I.
build: main.o sales.o
	$(CC) -o sales main.o sales.o

debug: main.cpp sales.cpp
	$(CC) -g -o sales main.cpp sales.cpp

clean:
	rm *.o *.out sales
