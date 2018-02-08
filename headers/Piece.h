#ifndef _PIECE_
#define _PIECE_

#include "allPieces.h"

class Piece
{
public:
	Piece();
	void setCurrentX(int x);
	int getCurrentX();
	
	void setCurrentY(int y);
	int getCurrentY();
	
	void setOldX(int x);
	int getOldX();
	
	void setOldY(int y);
	int getOldY();
	
	void setCurrentShape(int shapeType);
	int getCurrentShape();
	
	void setCurrentRotation(int rotation);
	int getCurrentRotation();
	
	void setOldRotation(int rotation);
	int getOldRotation();
	
	char getBlock(int shapeType, int rotation, int x, int y);
	
	void setIsStuck(bool toSet);
	bool getPieceIsStuck();
	
private:
	int currentX;
	int currentY;
	int oldX;
	int oldY;
	int currentShape;
	int currentRotation;
	int oldRotation;
	bool pieceIsStuck;
};

#endif