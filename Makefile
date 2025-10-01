CXX = g++
CXXFLAGS = -std=c++20 -Wall -Wextra -I/opt/homebrew/include
TARGET = main
SRC = main.cpp functions.cpp
LIBS = -L/opt/homebrew/lib -lssl -lcrypto

all: $(TARGET)

$(TARGET): $(SRC)
	$(CXX) $(CXXFLAGS) $(SRC) $(LIBS) -o $(TARGET)

run: $(TARGET)
	./$(TARGET)

clean:
	rm -f $(TARGET)

.PHONY: all run clean