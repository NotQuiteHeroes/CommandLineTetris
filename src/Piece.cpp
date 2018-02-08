#include "headers\Piece.h"

//constructor, sets currentX and currentY to starting position on the board
Piece::Piece()
{
								currentX = -1;
								currentY = 3;
								oldX = currentX;
								oldY = currentY;
								currentRotation = 0;
								oldRotation = currentRotation;
								pieceIsStuck = false;
}

//sets currentX to given x location
void Piece::setCurrentX(int x)
{
								currentX = x;
}

//return current x location of piece on board
int Piece::getCurrentX()
{
								return currentX;
}

//sets currentY to given y location
void Piece::setCurrentY(int y)
{
								currentY = y;
}

//returns current y location of piece on board
int Piece::getCurrentY()
{
								return currentY;
}

//set oldX, or the previous location of x before moving
void Piece::setOldX(int x)
{
								oldX = x;
}

//return old x position of piece
int Piece::getOldX()
{
								return oldX;
}

//set oldY, or the previous location of y before moving piece
void Piece::setOldY(int y)
{
								oldY = y;
}

//get old y position of piece
int Piece::getOldY()
{
								return oldY;
}

//set the current shape type. Used to index allPieces array
void Piece::setCurrentShape(int shapeType)
{
								currentShape = shapeType;
}

//return current shape type
int Piece::getCurrentShape()
{
								return currentShape;
}

//set the current rotation of piece. Used to index allPieces array
void Piece::setCurrentRotation(int rotation)
{
								currentRotation = rotation;
}

//return current rotation of piece
int Piece::getCurrentRotation()
{
								return currentRotation;
}

void Piece::setOldRotation(int rotation)
{
								oldRotation = rotation;
}

int Piece::getOldRotation()
{
								return oldRotation;
}

//return character at given x and y location. Needs the piece's shapeType and rotation to index allPieces array
char Piece::getBlock(int shapeType, int rotation, int x, int y)
{
								return allPieces[shapeType][rotation][x][y];
}

void Piece::setIsStuck(bool toSet)
{
								pieceIsStuck = toSet;
}

bool Piece::getPieceIsStuck()
{
								return pieceIsStuck;
}
