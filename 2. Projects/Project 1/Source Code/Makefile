CC = g++
DEBUG = -g -O0 -pedantic-errors
CFLAGS = -Wall -std=c++11 -c $(DEBUG)
LFLAGS = -Wall $(DEBUG)

All: p1

p1: p1.o SuperMarket.o LinkedList.o Queue.o Stack.o Order.o
	$(CC) $(LFLAGS) -o p1 p1.o SuperMarket.o LinkedList.o Queue.o Stack.o Order.o

p1.o: p1.cpp
	$(CC) $(CFLAGS) p1.cpp

SuperMarket.o: SuperMarket.cpp SuperMarket.h
	$(CC) $(CFLAGS) SuperMarket.cpp

LinkedList.o: LinkedList.cpp LinkedList.h
	$(CC) $(CFLAGS) LinkedList.cpp

Queue.o: Queue.cpp Queue.h
	$(CC) $(CFLAGS) Queue.cpp

Stack.o: Stack.cpp Stack.h
	$(CC) $(CFLAGS) Stack.cpp

Order.o: Order.cpp Order.h
	$(CC) $(CFLAGS) Order.cpp

.PHONY: clean

run: 
	make
	./p1 input.txt

clean:
	rm -rf *.o
	rm -rf p1
	rm -rf shippingLabels.txt

