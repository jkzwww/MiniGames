

#ifndef HURKLE_H
#define HURKLE_H

#include "basic.h"

void startHurkle();
void playHurkle();

void displayTitle();
void displayGrid();

bool checkLocation(string loc, int hX, int hY);
void resetGrid();

void gameOver(bool found, int hX, int hY);

#endif // !HURKLE_H

