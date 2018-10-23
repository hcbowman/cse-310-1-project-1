CC=g++
CPPFLAGS=--std=c++11 -Wall -pedantic

all: main.cpp heap.o util.o
	$(CC) $(CPPFLAGS) main.cpp heap.o util.o -o a

heap.o: heap.cpp
	$(CC) $(CPPFLAGS) -c heap.cpp

util.o: util.cpp
	$(CC) $(CPPFLAGS) -c util.cpp

clean:
	rm -f *.o *.exe *.stackdump
