
#ifndef TICTACTOE_H
#define TICTACTOE_H

#include "basic.h"

char playerPiece, compPiece, winnerPiece;
vector<char> board(9);
bool isGameOver;
int currentPlayer;


void setGamePiece(string letter);
void resetBoard();

#endif // !TICTACTOE_H

