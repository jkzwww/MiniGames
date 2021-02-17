
#ifndef TICTACTOE_H
#define TICTACTOE_H

#include "basic.h"



void playOX(int playerNum);

void setMultiPlayerPiece(string gamePieceChoice);
void setGamePiece(string letter);

void resetBoard();
void displayBoard();

bool isMoveLegal(int location);
void playerMove(int currentPlayer);
void humanMove();
void computerMove();

bool checkGameOver();
void gameOver(int numPlayer);

#endif // !TICTACTOE_H

