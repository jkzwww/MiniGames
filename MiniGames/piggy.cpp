
#include "piggy.h"

const int PLAYER_NUM = 2;
string playerNames[2];
int playerScores[2];
int diceSize;
int targetScore;

void startPiggy()
{
	//seed randoms
	srand(unsigned(time(NULL))); 

	//display rules
	displayPiggyTitle();
	displayText("LittlePiggy.txt");
	waitForPlayer();

	playPiggy();

}

void playPiggy()
{
	resetGame();
	displayGameScores();
	displayPiggyTitle();

	int diceRoll = 0;
	int diceTotal = 0;
	bool isGameOver = false;
	int currentPlayer = 0;
	string choice;

	while (!isGameOver)
	{
		cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";
		cout << "It's your turn, " << playerNames[currentPlayer];
		choice = askForString("Do you want to [r]oll or [b]ank? ");

		if (choice == "r" || choice == "R")
		{
			diceRoll = rand() % 6 + 1;

			if (diceRoll != 1)
			{
				diceTotal += diceRoll;
				cout << "\n\nYou rolled: " << diceRoll << "\t Total: " << diceTotal << "\n";
			}
			else
			{
				diceTotal = 0;
				cout << "\n\nYou rolled: " << diceRoll << "\t Total: " << diceTotal << "\n";
				displayGameScores();
				currentPlayer = swapPlayers(currentPlayer,PLAYER_NUM);
			}

		}
		else if (choice == "b" || choice == "B")
		{
			playerScores[currentPlayer] += diceTotal;
			diceTotal = 0;
			isGameOver = checkGameOver(currentPlayer);
			currentPlayer = swapPlayers(currentPlayer,PLAYER_NUM);
			displayGameScores();
		}
		else
		{
			cout << "\nInvalid input,please enter [r] or [b]!\n";
			waitForPlayer();
		}


	}

	//gameover
	currentPlayer = swapPlayers(currentPlayer,PLAYER_NUM); //swapback 
	GameOver(currentPlayer);

	waitForPlayer();

}


void resetGame()
{
	for (int i = 0; i < PLAYER_NUM; i++)
	{
		string name = askForString("\nEnter player name:");
		playerNames[i] = name;
		playerScores[i] = 0;
	}

	diceSize = 6;
	targetScore = 100;

	waitForPlayer();
}


void displayPiggyTitle()
{
	cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";
	cout << "\t\t (oo) Little Piggy (oo) \n";
	cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";
}


void displayGameScores()
{
	cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";

	cout << "Score to beat: " << targetScore << "\t\tDice Size: " << diceSize;

	cout << "\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";

	for (int i = 0; i < PLAYER_NUM; i++)
	{
		cout << "Player: " << playerNames[i] << "\t\t";
	}

	cout << "\n";

	for (int i = 0; i < PLAYER_NUM; i++)
	{
		cout << "Score: " << playerScores[i] << "\t\t";
	}

	cout << "\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";

	waitForPlayer();
}



bool checkGameOver(int currentPlayer)
{
	if (playerScores[currentPlayer] >= targetScore)
	{
		return true;
	}
	else
	{
		return false;
	}
}


void GameOver(int currentPlayer)
{
	string replay;

	displayPiggyTitle();
	cout << "The winner is: " << playerNames[currentPlayer];
	cout << "\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";

	replay = askForString("Do you want to play again? (y/n): ");

	if (replay == "y" || replay == "Y")
	{
		playPiggy();
	}
	else
	{
		cout << "\n\nThanks for playing, " << playerNames[currentPlayer] << "\n\n";
		waitForPlayer();
	}
}
