DBG = -g
OPTS = $(DBG) -Wall -ansi -pedantic -std=c++20

CC = g++ -c $(OPTS)
LN = g++

OBJS = main.o ListNode.o LinkedList.o

llist: $(OBJS)
	$(LN) -o llist $(OBJS)

main.o: main.cpp LinkedList.hpp ListNode.hpp
	$(CC) main.cpp

ListNode.o: ListNode.cpp ListNode.hpp
	$(CC) ListNode.cpp

LinkedList.o: LinkedList.cpp LinkedList.hpp
	$(CC) LinkedList.cpp

clean:
	/bin/rm -rf $(OBJS) llist *~
