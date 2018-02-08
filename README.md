# CommandLineTetris
Play Tetris on the command line!

Programming II Final

## Start of Game
![alt text](https://github.com/NotQuiteHeroes/Resources/blob/master/ScreenShots/tetris_startOfGame.JPG "Logo Title Text 1")


## GamePlay
![alt text](https://github.com/NotQuiteHeroes/Resources/blob/master/ScreenShots/tetris_gamePlay.JPG "Logo Title Text 1")


## Clearing a Line
![alt text](https://github.com/NotQuiteHeroes/Resources/blob/master/ScreenShots/tetris_clearingALine.JPG "Logo Title Text 1")


## Compilation:
cd src


g++ *.cpp


## Usage:
Use the wasd keys for movement.
+ a moves left
+ d moves right
+ s moves down
+ w rotates the shape

## Files:
+ allPieces contains the piece shapes
+ Board contains methods for initializing an empty board, determining if a space is free, displaying the board, deleting a line, and clearing a piece after it has moved.
+ Piece acts as a single shape on the board. Contains methods to get (x, y) position of top-left of shape, save (x, y) coordinates of previous position after shape moves, rotating shapes, getting the shape of the shape, and determining if a shape is stuck.
+ Gameplay contains methods for the overall game, such as getting a new shape when one has settled at the bottom, getting the movement input from the user, determining if a shape movement is valid, determining if the game is over, and scoring points.
