#include <iostream>

#define MAXSIZE 100

using namespace std;

char board[MAXSIZE][MAXSIZE];
int boardSize;

void initBoard()
{
	for(int row=0 ; row<boardSize; row++)
	{
		for(int col=0; col<boardSize; col++)
			board[row][col] = ' ';
	}
}

void printHeader()
{
	// print first +
	cout << "+";
	
	//  -+-+-+-+-+-+-+-+
	for (int numCells=0; numCells<boardSize; numCells++)
	{
		cout << "-+";
	}
	cout << endl;
}

void printBoard()
{
	for(int row=0 ; row<boardSize; row++)
	{
		// print row header
		printHeader();
		
		// print actual board data
		cout << '|';
		for(int col=0; col<boardSize; col++)
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
	
	// check to see if there is already a queen on the upper left diagonal
	int offset = 1;
	while ( inRow-offset >= 0 && inCol-offset >= 0 )
	{
		if (board[inRow-offset][inCol-offset]=='Q')
			return false;
		offset++;
	}
	// check to see if there is already a queen on the lower left diagonal
	offset = 1;
	while ( inRow+offset < boardSize && inCol-offset >= 0 )
	{
		if (board[inRow+offset][inCol-offset]=='Q')
			return false;
		offset++;
	}
	
	// if any of the above three cases are in play, return false
	//   otherwise return true
	
	return true;
}
bool solveBoard(int fromCol) 
{
	// if we went "off the right edge" ... solved!
	if (fromCol >= boardSize) 
		return true;
	
	// try each row as a queen until one works ...	
	for (int testRow=0; testRow<boardSize; testRow++)
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


