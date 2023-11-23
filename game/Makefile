CXXFLAGS = -std=c++17 -Wall -pedantic-errors
client/ProjA: client/main.o client/engine/engine.o
	g++ $(CXXFLAGS) -o client/ProjA client/main.o client/engine/engine.o
client/main.o: client/main.cpp
	g++ $(CXXFLAGS) -c -o client/main.o client/main.cpp
client/engine/engine.o: client/engine/engine.hpp client/engine/engine.ipp
	g++ $(CXXFLAGS) -c -o client/engine/engine.o -I./client/engine/ client/engine/engine.ipp
clean:
	rm client/*.o client/engine/*.o