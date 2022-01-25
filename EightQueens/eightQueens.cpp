#include <iostream>

#define BSIZE 8

using namespace std;

char board[BSIZE][BSIZE];

void initBoard()
{
	for(int row=0 ; row<BSIZE; row++)
	{
		for(int col=0; col<BSIZE; col++)
			board[row][col] = ' ';
	}
}

void printHeader()
{
	// print first +
	cout << "+";
	
	//  -+-+-+-+-+-+-+-+
	for (int numCells=0; numCells<BSIZE; numCells++)
	{
		cout << "-+";
	}
	cout << endl;
}

void printBoard()
{
	for(int row=0 ; row<BSIZE; row++)
	{
		// print row header
		printHeader();
		
		// print actual board data
		cout << '|';
		for(int col=0; col<BSIZE; col++)
			cout << board[row][col] << "|";
		cout << endl;
	}
	printHeader();
}
bool canPlace(int inRow, int inCol)
{
	// Homework : write this!
	
	// check to see if there is alread a queen on the same row
	for (int testCol=0; testCol < inCol; testCol++)
	{
		if (board[inRow][testCol] == 'Q')
			return false;
	}
	
	// check to see if there is alread a queen on the upper left diagonal
	
	// check to see if there is alread a queen on the lower left diagonal
	
	// if any of the above three cases are in play, return false
	//   otherwise return true
	
	return false;
}
bool solveBoard(int fromCol) 
{
	// if we went "off the right edge" ... solved!
	if (fromCol >= BSIZE) 
		return true;
	
	// try each row as a queen until one works ...	
	for (int testRow=0; testRow<BSIZE; testRow++)
	{
		if (canPlace(testRow, fromCol))
		{
			board[testRow][fromCol]='Q';
			bool itWorked = solveBoard(fromCol+1);
			
			if (itWorked)
				return true;
				
			// didn't work, so try another queen location
			board[testRow][fromCol]=' ';			
		}
	}
	// if we get here, we tried all rows for this queen ...
	//   ... and none worked !  Means we can't solve the problem!
	return false;
}
 
void solveBoard()
{
	bool answerFound = solveBoard(0);
	if (!answerFound) 
		cout << "No answer found!!!" << endl;
}

int main(int argc, char *argv[])
{
  initBoard();
  
  cout << "The empty Board:" << endl;
  printBoard();
  
  solveBoard();
  
  cout << "The solved Board:" << endl;
  printBoard();
  
  return 0;
}
