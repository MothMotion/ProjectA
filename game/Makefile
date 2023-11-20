build_client: ProjA
ProjA: client/main.o client/engine.o -o ProjA
	g++ client/main.o -I client/engine.o -o ProjA
cleint/main.o: client/main.cpp
	g++ client/main.cpp -o client/main.o
client/engine.o: client/engine.h client/engine.cpp
	g++ client/engine.h client/engine.cpp -o client/engine.o
