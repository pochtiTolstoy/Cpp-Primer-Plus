CXX = g++
CXXFLAGS = -Wall
LDFLAGS =
OBJFILES = main.o tv.o
TARGET = TV

all: $(TARGET)

$(TARGET): $(OBJFILES)
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(OBJFILES) $(LDFLAGS)

clean:
	rm -f $(OBJFILES) $(TARGET)
