CC=g++
CFLAGS=-I.
build: main.cpp dma.cpp
	$(CC) main.cpp dma.cpp -o dma

debug: main.cpp dma.cpp
	$(CC) -g main.cpp dma.cpp -o dma

test: test.cpp
	$(CC) -g test.cpp -o test

clean:
	rm *.o *.out dma test
