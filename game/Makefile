CXX=g++
CXXFLAGS=-Wall -Wextra
client/ProjA: client/main.o client/engine/libengine.so
	$(CXX) $(CXXFLAGS) -o $@ client/main.o -L./client/engine -lengine
client/main.o: client/main.cpp client/engine/libengine.so
	$(CXX) $(CXXFLAGS) -o $@ client/main.cpp
client/engine/libengine.so: client/engine/engine.h client/engine/vector.cpp
	$(CXX) $(CXXFLAGS) -o $@ -c client/engine/vector.cpp
clean:
	rm -f client/*.o client/engine/libengine.so
