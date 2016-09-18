#include "Board.h"
#include "Piece.h"
#include<iostream>

#define HEIGHT 21
#define WIDTH 11

//constructor. Initializes blank board
Board::Board()
{
	for(int i = 0; i < HEIGHT; i++)
	{
		for(int j = 0; j < WIDTH; j++)
		{
			if(i == HEIGHT - 1 || j == 0 || j == WIDTH-1)
			{
				currentBoard[i][j] = '#';
			}
			
			else
			{
				currentBoard[i][j] = ' ';
			}
		}		
	}
}

//return character at block on board given the x and y coordinate
char Board::getBlock(int x, int y)
{
	return currentBoard[x][y];
}

//set block at given x, y coordinates (corresponding to row and column respectively) to
//the given character 
void Board::setBlock(int x, int y, char charToSet)
{
	currentBoard[x][y] = charToSet;
}

//check if board has completed rows to clear
bool Board::checkBoard()
{
	int filled = 0;
	
	for(int i = 1; i < WIDTH - 1; i++)
	{
		if(getBlock(19, i) == 'X')
		{
			filled += 1;
		}
	}
	
	if(filled == 9)
	{
		deleteLine();
		return true;
	}
	
	return false;
	
}
			
//given row to delete; will clear out row and move all other rows down one
void Board::deleteLine()
{
	for(int i = HEIGHT - 2; i > 0; i--)
	{
		for(int j = 1; j < WIDTH - 1; j++)
		{
			char newBlock = getBlock(i - 1, j);
			setBlock(i, j, newBlock);
		}
	}
}

//saves piece to board
void Board::updateBoard(Piece piece)
{
	//holds current piece information
	int currentX = piece.getCurrentX();
	int currentY = piece.getCurrentY();
	int shapeType = piece.getCurrentShape();
	int rotation = piece.getCurrentRotation();
	
	int oldX = piece.getOldX();
	int oldY = piece.getOldY();
	
	clearPiece(piece, oldX, oldY);
	
	for(int i = 0; i < 5; i++)
	{
		for(int j = 0; j < 5; j++)
		{	
			//get each block of piece, if its an x save its position to the board
			char currentPieceBlock = piece.getBlock(shapeType,rotation, i, j);
			if(currentPieceBlock == 'X')
			{
				currentBoard[i+currentX][j+currentY] = currentPieceBlock;
			}
		}
	}
}

//print out current board
void Board::displayBoard()
{
	for(int i = 0; i < HEIGHT; i++)
	{
		for(int j = 0; j < WIDTH; j++)
		{
			std::cout<<getBlock(i, j)<<" ";
		}
	std::cout<<std::endl;
	}
}

void Board::clearPiece(Piece piece, int x, int y)
{
	int currentShape = piece.getCurrentShape();
	int currentRotation = piece.getCurrentRotation();
	int oldRotation = piece.getOldRotation();
	
	for(int i = 0; i < 5; i++)
	{
		for(int j = 0; j < 5; j++)
		{
			char currentBlock = piece.getBlock(currentShape, currentRotation, i, j);
			char previousBlock = piece.getBlock(currentShape, oldRotation, i, j);
			
			if((currentBlock == 'X' || previousBlock == 'X') && getBlock(i + x, j + y) != '#')
			{
				currentBoard[i+x][y+j] = ' ';
			}
		}
	}
}