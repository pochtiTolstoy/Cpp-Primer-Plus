CC=g++
CFLAGS=-I.
build: main.cpp worker.cpp
	$(CC) main.cpp worker.cpp -o worker

debug: main.cpp worker.cpp
	$(CC) -g main.cpp worker.cpp -o worker

clean:
	rm *.o *.out worker
