
#ifndef HANGMAN_H
#define HANGMAN_H

#include "basic.h"

void startHangman();
void readData();

string generateWord(int difficulty);
string generateGuessWord(string word, string letter, string halfSolved);
bool isLetterContained(string word, string letter);

void playHangman();

void displayHangman(int guessleft);

#endif // !HANGMAN_H

