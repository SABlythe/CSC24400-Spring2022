#include <iostream>

using namespace std;

void solveBoard();
void initBoard();
void printBoard();

extern int boardSize;

int main(int argc, char *argv[])
{
  cout << "How many queens in your problem? ";
  cin >> boardSize; 


  initBoard();
  
  cout << "The empty Board:" << endl;
  printBoard();
  
  solveBoard();
  
  cout << "The solved Board:" << endl;
  printBoard();
  
  return 0;
}
