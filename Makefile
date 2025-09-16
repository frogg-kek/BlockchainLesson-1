CXX = g++
CXXFLAGS = -std=c++20 -Wall -Wextra
TARGET = main
SRC = main.cpp functions.cpp

all: $(TARGET)

$(TARGET): $(SRC)
	$(CXX) $(CXXFLAGS) $(SRC) -o $(TARGET)

clean:
	rm -f $(TARGET)