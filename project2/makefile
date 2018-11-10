CC=g++
CPPFLAGS=--std=c++11 -Wall -pedantic

all: main.cpp heap.o util.o graph.o
	$(CC) $(CPPFLAGS) main.cpp heap.o util.o graph.o -o a #DONT FORGET TO CHANGE BACK TO proj2

heap.o: heap.cpp
	$(CC) $(CPPFLAGS) -c heap.cpp

util.o: util.cpp
	$(CC) $(CPPFLAGS) -c util.cpp

graph.o: graph.cpp
	$(CC) $(CPPFLAGS) -c graph.cpp

clean:
	rm -f *.o *.exe *.stackdump
