#include "Gameplay.h"
#include "Piece.h"
#include "Board.h"

#include<cstdlib>
#include<ctime>
#include<iostream>
#include<cstdio>

#define HEIGHT 21
#define WIDTH 11

//constructor. Initialize horizontalChange and verticalChange to 0 to start
Gameplay::Gameplay()
{
	int horizontalChange = 0;
	int verticalChange = 0;
	int points = 0;
}

//given a piece object. Sets new shape type and rotation of next piece
void Gameplay::getNextPiece(Piece &piece)
{
	int newShape = std::rand() % 7;
	int newRotation = std::rand() % 4;
	
	piece.setCurrentShape(newShape);
	
	piece.setCurrentRotation(newRotation);
	piece.setOldRotation(newRotation);
	
	piece.setCurrentX(-1);
	piece.setCurrentY(3);
	
	piece.setOldX(-1);
	piece.setOldY(3);
	
	piece.setIsStuck(false);
	
}

//get character input from user, return int based on what movement should be made	
int Gameplay::getMovement()
{
	//char movement;
	char movement;
	std::cin>>movement;
	
	switch(movement)
	{
		//rotate
		case 'w':
			return 1;
			break;
		//left
		case 'a':
			return 2;
			break;
		//down
		case 's':
			return 3;
			break;
		//right
		case 'd':
			return 4;
			break;
		//quit
		case 'q':
			return 5;
			break;
		//default is same as down
		default:
			return 3;
			break;
	}
}

//check valid move given board, piece, and movement to check
bool Gameplay::validMove(Board board, Piece &piece, int movement)
{
	//current piece information
	int currentX = piece.getCurrentX();
	int currentY = piece.getCurrentY();
	int currentShape = piece.getCurrentShape();
	int currentRotation = piece.getCurrentRotation();
	int newRotation;
	
	board.clearPiece(piece, currentX, currentY);
		
	//check movement
	switch(movement)
	{
		//rotate
		case 1:
			//if current rotation is last possible rotation start over at 0
			if(currentRotation == 3)
			{
				piece.setOldRotation(3);
				
				newRotation = 0;
				
				for(int i = 0; i < 5; i++)
				{
					for(int j = 0; j < 5; j++)
					{
						//if block in piece is an 'X'
						if(piece.getBlock(currentShape, newRotation, i, j)=='X')
						{
							//and block at board in new position isn't free
							if(board.getBlock(currentX+i, currentY+j)!= ' ')
							{
							
							//not a valid move
							piece.setIsStuck(isStuck(board, piece));
						
							return false;
							}
						}
					}
				}
				
				piece.setCurrentRotation(0);
			}
			
			//otherwise add one to currentRotation
			else
			{
				piece.setOldRotation(currentRotation);
				newRotation = piece.getCurrentRotation() + 1;
				
				for(int i = 0; i < 5; i++)
				{
					for(int j = 0; j < 5; j++)
					{
						//if block in piece is an 'X'
						if(piece.getBlock(currentShape, newRotation, i, j)=='X')
						{
							//and block at board in new position isn't free
							if(board.getBlock(currentX+i, currentY+j)!= ' ')
							{
							piece.setIsStuck(isStuck(board, piece));
								//not a valid move
							return false;
							}
						}
					}
				}
				
				piece.setCurrentRotation(currentRotation + 1);
			}
			
			horizontalChange = 0;
			verticalChange = 0;
			
			break;
		
		//left
		case 2:
			horizontalChange = -1;
			verticalChange = 0;
			break;
			
		//down
		case 3:
			horizontalChange = 0;
			verticalChange = 1;
			break;
			
		//right	
		case 4:
			horizontalChange = 1;
			verticalChange = 0;
			break;
		
		//quit
		case 5:
			quitGame();
			break;
		
		//default will still move down one
		default:
			horizontalChange = 0;
			verticalChange = 1;
			break;
	}
	
	//new x and y position of piece based on proposed movement
	int newX = currentX + verticalChange;
	int newY = currentY + horizontalChange;	
	
	for(int i = 0; i < 5; i++)
	{
			for(int j = 0; j < 5; j++)
			{
				//if block in piece is an 'X'
				if(piece.getBlock(currentShape, currentRotation, i, j)=='X')
				{
					//and block at board in new position isn't free
					if(board.getBlock(newX+i, newY+j)!= ' ')
					{
						//not a valid move
						piece.setIsStuck(isStuck(board, piece));
						return false;
					}

				}
			}
	}
	
	
	//if valid move, set old x and y coordinate of piece to currentX and currentY
	piece.setOldX(currentX);
	piece.setOldY(currentY);
	
	//then change currentX and currentY to new coordinates
	piece.setCurrentX(newX);
	piece.setCurrentY(newY);
	
	//valid move
	return true;
}


//test if piece is stuck; needs board and current piece
bool Gameplay::isStuck(Board board, Piece piece)
{
	//currentPiece information
	int currentX = piece.getCurrentX();
	int lastRow = getLastRow(piece);
	if(lastRow == 0){std::cout<<"Error"<<std::endl;}
	int currentY = piece.getCurrentY();
	int currentShape = piece.getCurrentShape();
	int currentRotation = piece.getCurrentRotation();
	
	for(int i = 0; i < 5; i++)
	{

			if((board.getBlock(currentX + lastRow + 1, currentY + i) != ' ') && (piece.getBlock(currentShape, currentRotation, lastRow, i) == 'X'))
			{
				return true;
			}
	}
	
	return false;
}


//save piece movement to board
void Gameplay::makeMove(Board &board, Piece &piece)
{
	//current piece information
	int shapeType = piece.getCurrentShape();
	int rotation = piece.getCurrentRotation();
	int currentX = piece.getCurrentX();
	int currentY = piece.getCurrentY();

	//previous location of piece
	int oldX = piece.getOldX();
	int oldY = piece.getOldY();
	
	board.clearPiece(piece, oldX, oldY);
	
	//set new piece on board
	for(int i = 0; i < 5; i++)
	{
		for(int j = 0; j < 5; j++)
		{
			char currentBlock = piece.getBlock(shapeType, rotation, i, j);
			if(currentBlock == 'X')
			{
				board.setBlock(i+currentX, j+currentY, 'X');
			}
		}
	}
}


//checks if game is over by seeing if first row is filled
bool Gameplay::gameOver(Board board)
{
	for(int i = 0; i < WIDTH; i++)
	{
		if(board.getBlock(0, i) == 'X')
		{
			return true;
		}
	}
	
	return false;
}

//exits game
void Gameplay::quitGame()
{
	std::cout<<"Goodbye!"<<std::endl;
	exit(0);
}

int Gameplay::getLastRow(Piece piece)
{
	int currentShape = piece.getCurrentShape();
	int currentRotation = piece.getCurrentRotation();

	for(int i = 5; i > 0; i--)
	{
		for(int j = 5; j > 0; j--)
		{
			if(piece.getBlock(currentShape, currentRotation, i, j) == 'X')
			{
				return i;
			}
		}
	}
	
	return 0;
}

void Gameplay::addPoints()
{
	points += 1;
}

int Gameplay::getPoints()
{
	return points;
}