CC=g++
CFLAGS=-I.
build: main.o chaff.o
	$(CC) -o chaff main.o chaff.o

debug: main.cpp chaff.cpp
	$(CC) -g -o chaff main.cpp chaff.cpp

clean:
	rm *.o *.out chaff
