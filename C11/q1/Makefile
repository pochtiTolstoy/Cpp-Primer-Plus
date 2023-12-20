CC=g++
CFLAGS=-I.
build: stone.o stonewt.o
	$(CC) -o stone stone.o stonewt.o

debug: stone.cpp stonewt.cpp
	$(CC) -g -o stone stone.cpp stonewt.cpp

test: test.cpp
	$(CC) -g -o test test.cpp

clean:
	rm *.o *.out stone test
