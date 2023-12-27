CC=g++
CFLAGS=-I.
build: main.cpp queue.cpp
	$(CC) main.cpp queue.cpp -o queue

debug: main.cpp queue.cpp
	$(CC) -g main.cpp queue.cpp -o queue

clean:
	rm *.o *.out queue
