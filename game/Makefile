client/ProjA: client/main.o client/engine/engine.o
	g++ -o client/ProjA client/main.o client/engine/engine.o
client/main.o: client/main.cpp
	g++ -c -o client/main.o client/main.cpp
client/engine/engine.o: client/engine/engine.hpp client/engine/engine.ipp
	g++ -c -o client/engine/engine.o client/engine/engine.ipp
clean:
	rm client/*.o client/engine/*.o