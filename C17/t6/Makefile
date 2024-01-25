CXX = g++
CXXFLAGS = -Wall
LDFLAGS =
OBJFILES = main.o emp.o
SRCFILES = main.cpp emp.cpp
TARGET = EMP

all: $(TARGET)

$(TARGET): $(OBJFILES)
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(OBJFILES) $(LDFLAGS)

debug: $(SRCFILES)
	$(CXX) -g $(CXXFLAGS) -o $(TARGET) $(SRCFILES)

clean:
	rm -f $(OBJFILES) $(TARGET)
