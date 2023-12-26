CC=g++
CFLAGS=-I.
build: main.cpp stack.cpp
	$(CC) main.cpp stack.cpp -o stack

debug: main.cpp stack.cpp
	$(CC) -g main.cpp stack.cpp -o stack

clean:
	rm *.o *.out stack
