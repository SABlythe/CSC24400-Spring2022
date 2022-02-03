solver: main.o eightQueens.o
	g++ -o solver main.o eightQueens.o
	
main.o: main.cpp eightQueens.hpp
	g++ -g -c -Wall -ansi -pedantic main.cpp
	
eightQueens.o: eightQueens.cpp eightQueens.hpp
	g++ -g -c -Wall -ansi -pedantic eightQueens.cpp
	
clean:
	/bin/rm -rf *.o solver 
 
	
	
