CC=g++
CFLAGS=-I.
build: main.cpp cow.cpp
	$(CC) main.cpp cow.cpp -o cow

debug: main.cpp cow.cpp
	$(CC) -g main.cpp cow.cpp -o cow

clean:
	rm *.o *.out cow
