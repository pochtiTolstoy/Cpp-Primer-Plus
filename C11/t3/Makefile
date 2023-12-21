CC=g++
CFLAGS=-I.
build: randwalk.o vect.o
	$(CC) -o randwalk randwalk.o vect.o

debug: randwalk.cpp vect.cpp
	$(CC) -g -o randwalk randwalk.cpp vect.cpp

clean:
	rm *.o *.out randwalk
