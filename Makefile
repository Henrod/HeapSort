CXX = g++

CPP_FILES = $(wildcard src/*.cpp)
OBJ_FILES := $(addprefix obj/,$(notdir $(CPP_FILES:.cpp=.o)))
BIN_FILES = obj/bin/main

CC_FLAGS = -Ihdr
CXXFLAGS = -std=c++11 -Wall -Wextra

all: $(OBJ_FILES)
	@mkdir -p obj/bin
	$(CXX) $(CXXFLAGS) $(CC_FLAGS) $^ -o $(BIN_FILES)

obj/%.o: src/%.cpp
	@mkdir -p obj/
	$(CXX) $(CXXFLAGS) $(CC_FLAGS) -c $^ -o $@

clean:
	rm -rf obj/*
