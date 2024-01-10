CC=g++
CFLAGS=-I.
build: main.cpp person.cpp gunslinger.cpp pokerplayer.cpp card.cpp baddude.cpp
	$(CC) main.cpp person.cpp gunslinger.cpp pokerplayer.cpp card.cpp baddude.cpp -o person

debug: main.cpp person.cpp gunslinger.cpp pokerplayer.cpp card.cpp baddude.cpp
	$(CC) -g main.cpp person.cpp gunslinger.cpp pokerplayer.cpp card.cpp baddude.cpp -o person

clean:
	rm *.o *.out person
