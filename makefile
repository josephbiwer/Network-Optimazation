
all: build/main build/Node build/Graph build/Network
	g++ $(CFLAGS) $^ -o build/run

build/main: src/main.cpp parameters.h
	g++ $(CFLAGS) -c -o $@ $<

build/Node: src/Node.cpp include/Node.h
	g++ $(CFLAGS) -c -o $@ $<

build/Graph: src/Graph.cpp include/Graph.h
	g++ $(CFLAGS) -c -o $@ $<

build/Network: src/Network.cpp include/Network.h parameters.h
	g++ $(CFLAGS) -c -o $@ $<
