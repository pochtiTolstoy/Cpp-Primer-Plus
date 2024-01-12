CXX = g++
CXXFLAGS = -Wall
LDFLAGS =
OBJFILES = main.o tv.o
SRCFILES = main.cpp tv.cpp
TARGET = TV

all: $(TARGET)

$(TARGET): $(OBJFILES)
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(OBJFILES) $(LDFLAGS)

debug: $(SRCFILES)
	$(CXX) -g $(CXXFLAGS) -o $(TARGET) $(SRCFILES)
clean:
	rm -f $(OBJFILES) $(TARGET)
