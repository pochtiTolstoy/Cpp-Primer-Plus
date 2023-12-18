CC=g++
CFLAGS=-I.
build: main.o bank.o
	$(CC) -o bank main.o bank.o

debug: main.cpp bank.cpp
	$(CC) -g -o bank main.cpp bank.cpp

clean:
	rm *.o *.out bank
