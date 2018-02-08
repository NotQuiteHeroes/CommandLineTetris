#ifndef _BOARD_
#define _BOARD_

#include "Piece.h"


class Board
{
public:
	Board();
	char getBlock(int x, int y);
	void setBlock(int x, int y, char charToSet);
	bool checkBoard();
	void deleteLine();
	void updateBoard(Piece piece);
	void displayBoard();
	void clearPiece(Piece piece, int x, int y);
	
private:
	char currentBoard[21][11];
};

#endif