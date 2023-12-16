#hellomake: hellomake.cpp hellofunc.cpp
#	g++ -o hellomake hellomake.cpp hellofunc.cpp -I.

CC=g++
CFLAGS=-I.
hellomake: hellomake.o hellofunc.o
	$(CC) -o hellomake hellomake.o hellofunc.o

clean:
	rm *.o hellomake
