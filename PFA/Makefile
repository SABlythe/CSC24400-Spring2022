DBG = -g
OPTS = $(DBG) -Wall -ansi -pedantic

CC = g++ -c $(OPTS)
LN = g++

OBJS = main.o PFA.o

arrayFun: $(OBJS)
	$(LN) -o arrayFun $(OBJS)

main.o: main.cpp PFA.hpp
	$(CC) main.cpp

PFA.o: PFA.cpp PFA.hpp
	$(CC) PFA.cpp

clean:
	/bin/rm -rf $(OBJS) arrayFun *~
