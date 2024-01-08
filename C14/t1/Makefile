CC=g++
CFLAGS=-I.
build: main.cpp Wine.cpp
	$(CC) main.cpp Wine.cpp -o wine

debug: main.cpp Wine.cpp
	$(CC) -g main.cpp Wine.cpp -o wine

clean:
	rm *.o *.out wine
