CXX = g++
CXXFLAGS = -std=c++23 -Wall -Wextra
TARGET = main
SRC = main.cpp

all: $(TARGET)

$(TARGET): $(SRC)
	$(CXX) $(CXXFLAGS) $(SRC) -o $(TARGET)

clean:
	rm -f $(TARGET)