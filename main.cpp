#include "headers\Gameplay.h"
#include "headers\Board.h"
#include "headers\Piece.h"

#include <ctime>
#include <cstdlib>
#include <iostream>

int main()
{
								Gameplay gameplay;
								Piece piece;
								Board board;

								bool gameOver = false;
								bool clearLines = false;

								std::srand(std::time(0));

								int randomShape = std::rand() % 7;
								piece.setCurrentShape(randomShape);
								piece.setCurrentRotation(0);

								do
								{
																board.updateBoard(piece);

																board.displayBoard();
																std::cout<<"Points: "<<gameplay.getPoints()<<std::endl;

																int move = gameplay.getMovement();
																bool validMove = gameplay.validMove(board, piece, move);


																if(validMove == true)
																{
																								board.updateBoard(piece);

																}
																else if(piece.getPieceIsStuck() == true)
																{
																								gameplay.getNextPiece(piece);
																								clearLines = board.checkBoard();

																								if(clearLines)
																								{
																																gameplay.addPoints();
																								}

																}

																gameOver = gameplay.gameOver(board);

								} while(gameOver != true);

								std::cout<<"Game Over!"<<std::endl;
}
