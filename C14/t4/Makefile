CXX = g++
CXXFLAGS = -Wall -Wno-comment
LDFLAGS =
OBJFILES = main.o person.o gunslinger.o pokerplayer.o baddude.o card.o
SRCFILES = main.cpp person.cpp gunslinger.cpp pokerplayer.cpp baddude.cpp card.cpp
TARGET = PERSON

all: $(TARGET)

$(TARGET): $(OBJFILES)
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(OBJFILES) $(LDFLAGS)

debug: $(SRCFILES)
	$(CXX) -g $(CXXFLAGS) -o $(TARGET) $(SRCFILES)

clean:
	rm -f $(OBJFILES) $(TARGET)
