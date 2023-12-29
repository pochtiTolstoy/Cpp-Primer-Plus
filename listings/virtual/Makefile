CC=g++
CFLAGS=-I.
build: main.cpp brass.cpp
	$(CC) main.cpp brass.cpp -o brass

debug: main.cpp brass.cpp
	$(CC) -g main.cpp brass.cpp -o brass

clean:
	rm *.o *.out brass
