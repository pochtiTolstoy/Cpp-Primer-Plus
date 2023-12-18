CC=g++
CFLAGS=-I.
build: main.o person.o
	$(CC) -o person main.o person.o

debug: main.cpp person.cpp
	$(CC) -g -o person main.cpp person.cpp

clean:
	rm *.out *.o person
