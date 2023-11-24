CXX=g++
CXXFLAGS=-Wall -Wextra -std=c++20
client/ProjA: client/main.o client/engine/vector.o
	$(CXX) $(CXXFLAGS) -o $@ client/main.o client/engine/vector.o
client/main.o: client/main.cpp client/engine/engine.h
	$(CXX) $(CXXFLAGS) -o $@ -c client/main.cpp
client/engine/vector.o: client/engine/engine.h client/engine/vector.cpp
	$(CXX) $(CXXFLAGS) -o $@ -c client/engine/vector.cpp
clean:
	rm -f client/*.o client/engine/*.o
