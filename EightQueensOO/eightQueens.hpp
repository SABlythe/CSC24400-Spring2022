#ifndef _EIGHT_QUEENS_HPP_
#define _EIGHT_QUEENS_HPP_

class EightQueens
{
private:
	int boardSize;

public:
	EightQueens(int numQueens) {boardSize = numQueens; }
	void solveBoard();
	void initBoard();
	void printBoard();

private:
	bool solveBoard(int fromCol);


};

#endif
