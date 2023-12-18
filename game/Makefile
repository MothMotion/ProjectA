CXX=g++
CXXFLAGS=-Wall -Wextra -std=c++20
client/ProjA: client/main.o client/engine/engine.o
	$(CXX) $(CXXFLAGS) -o $@ client/main.o client/engine/engine.o
client/main.o: client/main.cpp client/engine/engine.o
	$(CXX) $(CXXFLAGS) -o $@ -c client/main.cpp
client/engine/engine.o: client/engine/engine.h client/engine/vector.o client/engine/object.o
	$(CXX) $(CXXFLAGS) -o $@ -c client/engine/*.o
client/engine/vector.o: client/engine/engine.h client/engine/vector.cpp
	$(CXX) $(CXXFLAGS) -o $@ -c client/engine/vector*.cpp
client/engine/object.o: client/engine/engine.h client/engine/object.cpp
	$(CXX) $(CXXFLAGS) -o $@ -c client/engine/object*.cpp
client/engine/visual.o: client/engine/engine.h client/engine/object.cpp client/engine/vector.cpp
	$(CXX) $(CXXFLAGS) -o $@ -c client/engine/visual*.cpp
clean:
	rm -f client/*.o client/engine/*.o
build:
	$(CXX) $(CXXFLAGS) -o client/ProjA client/main.cpp client/engine/engine*.cpp client/engine/vector*.cpp client/engine/object*.cpp client/engine/visual*.cpp
