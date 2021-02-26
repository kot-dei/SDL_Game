CXX = g++
CXXFLAGS = -g -Wall -ansi -pedantic
LINKER_FLAGS_ONE = -lSDL2
LINKER_FLAGS_TWO = -lSDL2_image
Game.o: Game.cpp Game.h
	$(CXX) $(CXXFLAGS) -c $< -o $@
	
main: main.cpp Game.o
	$(CXX) $(CXXFLAGS) $^ $(LINKER_FLAGS_ONE) $(LINKER_FLAGS_TWO) -o $@
