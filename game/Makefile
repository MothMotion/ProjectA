CXX=g++
CXXFLAGS=
client/ProjA: client/main.o client/engine/engine.o
	$(CXX) $(CXXFLAGS) -o $@ $^
client/main.o: client/main.cpp client/engine/engine.o
	$(CXX) $(CXXFLAGS) -o $@ $<
client/engine/engine.o: client/engine/engine.h client/engine/engine.cpp
	$(CXX) $(CXXFLAGS) -o $@ client/engine/engine.cpp client/engine/engine.h
clean:
	rm -f client/*.o client/engine/*.o