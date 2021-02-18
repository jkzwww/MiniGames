
#include "EvenMinusOdd.h"

bool firstPlay = true;
int playerNum = 0;
int counterPool = 0;
vector<string> vNames;
vector<int> vScores;
const int MAX_DICE = 6;
int diceRolls[MAX_DICE];
int EMOcurrentPlayer = 0;


void startEvenMinusOdd()
{
	srand(unsigned(time(NULL))); //seed randoms

	if (firstPlay)
	{
		//rules
		displayEMOtitle();
		displayText("evenMinusOdd.txt");

		//initialise
		playerNum = askForNumber("Enter number of player (2-4): ",2,4);
		counterPool = playerNum * 10;

		for (int i = 0; i < playerNum; i++)
		{
			string name = askForString("Enter player name: ");
			vNames.push_back(name);
			vScores.push_back(0);
		}

		firstPlay = false;

		waitForPlayer();
		displayEMOtitle();
		displayGameStats();
	}

	playEvenMinusOdd();

	waitForPlayer();
}


void playEvenMinusOdd()
{
	bool isGameOver = false;
	int currentPlayer = rand() % playerNum;
	int result = 0;

	while (!isGameOver)
	{

		if (counterPool <= 0)
		{
			isGameOver = true;
		}
		else
		{
			cout << "\n\nIt's your turn: " << vNames[EMOcurrentPlayer] << endl;

			cout << "\nRoll the dice~ press any key!\n";

			system("pause");

			rollDice();

			result = calcResult();

			updateScores(EMOcurrentPlayer, result);

			waitForPlayer();
			displayEMOtitle();
			displayGameStats();

			EMOcurrentPlayer = swapPlayers(EMOcurrentPlayer, playerNum);
		}
	}

	displayWinner();
}


void displayEMOtitle()
{
	cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";
	cout << "\tEven Minus Odd :: A Game of Chance\n";
	cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";

}


void displayGameStats()
{
	cout << "Counters in the pool: " << counterPool << endl;
	cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";

	for (int i = 0; i < playerNum; i++)
	{
		cout << "Player: " << vNames[i] << "\t\t";
	}

	cout << "\n";

	for (int i = 0; i < playerNum; i++)
	{
		cout << "Score: " << vScores[i] << "\t\t";
	}

	cout << "\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";

}


void displayWinner()
{
	waitForPlayer();
	displayEMOtitle();
	displayGameStats();

	int highScore = 0;
	int winner = 0;

	for (int i = 0; i < playerNum; i++)
	{
		if (vScores[i] >= highScore)
		{
			highScore = vScores[i];
			winner = i;
		}
	}

	cout << "\nThe winner is: " << vNames[winner] << endl;

	cout << "\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n\n";

}


void rollDice()
{
	cout << "\nYou rolled: ";

	for (int i = 0; i < MAX_DICE; i++)
	{
		diceRolls[i] = rand() % 6 + 1;
		cout << diceRolls[i] << "  ";
	}

	cout << endl;
}


int calcResult()
{
	int even = 0;
	int odd = 0;

	for (int i = 0; i < MAX_DICE; i++)
	{
		if (diceRolls[i] % 2 == 0)
		{
			even += diceRolls[i];
		}
		else
		{
			odd += diceRolls[i];
		}
	}

	cout << "Your final result was: " << (even - odd) << "\n\n";

	return (even - odd);
}


void updateScores(int currentPlayer, int result)
{
	if (result > 0)
	{
		if (counterPool < result)
		{
			result = counterPool;
		}

		vScores[currentPlayer] += result;

		counterPool -= result;
	}
	else
	{
		result = abs(result);

		if (vScores[currentPlayer] < result)
		{
			result = vScores[currentPlayer];
		}

		vScores[currentPlayer] -= result;

		counterPool += result;
	}


}


