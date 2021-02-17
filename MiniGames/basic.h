
#ifndef BASIC_H
#define BASIC_H

#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <algorithm>
#include <ctime>
#include <sstream>

using namespace std;
 

void displayText(string myFileName);

string askForString(string question);
int askForNumber(string question, int min, int max);

void waitForPlayer();
int swapPlayers(int currentPlayer, int numPlayers);


#endif    