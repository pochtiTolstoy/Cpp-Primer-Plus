CC=g++
CFLAGS=-I.
build: main.o compl.o
	$(CC) -o compl main.o compl.o

debug: main.cpp compl.cpp
	$(CC) -g -o compl main.cpp compl.cpp

clean:
	rm *.o *.out compl
