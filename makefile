# Kaylan Mettus
# CS302
# Make file for assignment 6.

OBJS	= routerSim.o main.o radixTree.o
OBJS1	= radixTreeTest.o radixTree.o
CC	= g++
DEPS	= routerSim.h radixTree.h linkedQueue.h

all: main radixTreeTest

main: main.o routerSim.o radixTree.o $(DEPS)
	$(CC) -g -Wall -pedantic -o main $(OBJS)

main.o: main.cpp $(DEPS)
	$(CC) -g -Wall -pedantic -c main.cpp

routerSim.o: routerSim.cpp $(DEPS)
	$(CC) -g -Wall -pedantic -c routerSim.cpp
	
radixTree.o: radixTree.cpp $(DEPS)
	$(CC) -g -Wall -pedantic -c radixTree.cpp


radixTreeTest: radixTreeTest.o radixTree.o $(DEPS)
	$(CC) -g -Wall -pedantic -o radixTreeTest $(OBJS1)
	
radixTreeTest.o: radixTreeTest.cpp $(DEPS)
	$(CC) -g -Wall -pedantic -c radixTreeTest.cpp


# -----
# clean by removing object files.

clean:
	rm	$(OBJS)
