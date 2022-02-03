#include <iostream>

#include "eightQueens.hpp"

using namespace std;



int main(int argc, char *argv[])
{
  cout << "How many queens do you want to place? ";
  cin >> boardSize; 


  initBoard();
  
  cout << "The empty Board:" << endl;
  printBoard();
  
  solveBoard();
  
  cout << "The solved Board:" << endl;
  printBoard();
  
  return 0;
}
