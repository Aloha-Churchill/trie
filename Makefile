CXX=g++
CXXFLAGS=-std=c++11 -Wall -g

TARGET=trie_analyzer


SOURCES=Trie.cpp main.cpp
HEADERS=Trie.hpp
OBJECTS=$(SOURCES:.cpp=.o)

all: $(TARGET)

$(TARGET): $(OBJECTS)
	$(CXX) $(CXXFLAGS) -o $@ $^

%.o: %.cpp $(HEADERS)
	$(CXX) $(CXXFLAGS) -c $<

clean:
	rm -f $(TARGET) $(OBJECTS)

run: $(TARGET)
	./$(TARGET)
