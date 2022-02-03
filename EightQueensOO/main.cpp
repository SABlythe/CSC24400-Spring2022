#include <iostream>

#include "eightQueens.hpp"

using namespace std;



int main(int argc, char *argv[])
{

  
  
  cout << "How many queens do you want to place? ";
  
  int queenCount;
  cin >> queenCount; 

  EightQueens board(queenCount);

  board.initBoard();
  
  cout << "The empty Board:" << endl;
  board.printBoard();
  
  board.solveBoard();
  
  cout << "The solved Board:" << endl;
  board.printBoard();
  
  return 0;
}
