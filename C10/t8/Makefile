CC=g++
CFLAGS=-I.
build: main.o list.o
	$(CC) -o list main.o list.o

debug: main.cpp list.cpp
	$(CC) -g -o list main.cpp list.cpp

clean:
	rm *.o *.out list
