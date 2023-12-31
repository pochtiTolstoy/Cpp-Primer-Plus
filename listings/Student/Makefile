CC=g++
CFLAGS=-I.
build: main.cpp student.cpp
	$(CC) main.cpp student.cpp -o student

debug: main.cpp student.cpp
	$(CC) -g main.cpp student.cpp -o student

clean:
	rm *.o *.out student
