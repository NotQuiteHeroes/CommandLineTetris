#ifndef _GAMEPLAY_
#define _GAMEPLAY_

#include "Piece.h"
#include "Board.h"

class Gameplay
{
public:
	Gameplay();
	int points;
	void getNextPiece(Piece &piece);
	int getMovement();
	bool validMove(Board board, Piece &piece, int movement);
	bool isStuck(Board board, Piece piece);
	void makeMove(Board &board, Piece &piece);
	bool gameOver(Board board);
	void quitGame();
	int horizontalChange;
	int verticalChange;
	int getLastRow(Piece piece);
	void addPoints();
	int getPoints();
};

#endif