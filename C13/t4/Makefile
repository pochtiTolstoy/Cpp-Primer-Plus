CC=g++
CFLAGS=-I.
build: main.cpp port.cpp
	$(CC) main.cpp port.cpp -o port

debug: main.cpp port.cpp
	$(CC) -g main.cpp port.cpp -o port

test: test.cpp
	$(CC) test.cpp -o test

clean:
	rm *.o *.out port test
