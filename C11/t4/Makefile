CC=g++
CFLAGS=-I.
build: main.o time.o
	$(CC) -o time main.o time.o

debug: main.cpp time.cpp
	$(CC) -g -o time main.cpp time.cpp

clean:
	rm *.o *.out time
