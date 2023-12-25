CC=g++
CFLAGS=-I.
build: main.cpp stock.cpp
	$(CC) main.cpp stock.cpp -o stock

debug: main.cpp stock.cpp
	$(CC) -g main.cpp stock.cpp -o stock

clean:
	rm *.o *.out stock
