CC=g++
CFLAGS=-I.
build: main.cpp cd.cpp
	$(CC) main.cpp cd.cpp classic.cpp -o cd

debug: main.cpp cd.cpp
	$(CC) -g main.cpp cd.cpp classic.cpp -o cd

clean:
	rm *.o *.out cd
