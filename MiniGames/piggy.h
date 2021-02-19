
#ifndef PIGGY_H
#define PIGGY_H

#include "basic.h"

void startPiggy();
void playPiggy();

void resetGame();

void displayPiggyTitle();
void displayGameScores();

bool checkGameOver(int currentPlayer);
void GameOver(int currentPlayer);

#endif 

