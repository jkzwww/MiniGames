
#include "Hurkle.h"

const int GRID_SIZE = 10;
const int MAX_TURNS = 5;

string hurkleGrid[GRID_SIZE][GRID_SIZE];
string playerName = "";
int playerWins;
int hurkleWins;
bool replay;

void startHurkle()
{
	// seed randoms
	srand(unsigned(time(NULL)));

	system("cls");

	// display how to play text 
	displayText("hurkle.txt");

	// initialise game variables
	// ask for player’s name
	playerName = askForString("What is your name? ");
	playerWins = 0;
	hurkleWins = 0;

	waitForPlayer();

	playHurkle();
}

void playHurkle()
{

	int hX, hY; //hurkle hiding position
	string loc; //player guess
	int playerTurn = 0;
	bool isGameOver = false;
	bool found = false;

	hX = rand() % GRID_SIZE;
	hY = rand() % GRID_SIZE;

	resetGrid();
	displayGrid();

	while (!isGameOver)
	{
		//ask guess
		loc = askForString(playerName + ", enter your XY: ");
		waitForPlayer();

		//check location
		found = checkLocation(loc, hX, hY);

		//update turns and check game progress
		playerTurn++;
		if (playerTurn == 5 || found)
		{
			isGameOver = true;
		}

	}

	//display final stats
	//end program
	waitForPlayer();
	gameOver(found, hX, hY);

}



void displayTitle()
{
	cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";
	cout << "\t\t Hurkle!\n";
	cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";
}


void resetGrid()
{
	for (int row = 0; row < GRID_SIZE; row++)
	{
		for (int col = 0; col < GRID_SIZE; col++)
		{
			hurkleGrid[row][col] = ".";
		}
	}
}


void displayGrid()
{
	displayTitle();
	string line = "";
	cout << "\n\t\t North\n";

	for (int row = (GRID_SIZE - 1); row >= 0; row--)
	{
		if (row == 4)
		{
			line = "West	" + to_string(row) + " ";
		}
		else
		{
			line = "\t" + to_string(row) + " ";
		}

		for (int col = 0; col < GRID_SIZE; col++)
		{
			line += hurkleGrid[row][col] + " ";
		}

		if (row == 4)
		{
			cout << line + "	East\n";
		}
		else
		{
			cout << line << endl;
		}

	}

	cout << "\t  0 1 2 3 4 5 6 7 8 9\n";
	cout << "\t\t South\n\n";
}


bool checkLocation(string loc, int hX, int hY)
{
	string feedback = "";

	int X = stoi(to_string(loc[0])) - 48;
	int Y = stoi(to_string(loc[1])) - 48;

	if (hX == X && hY == Y)
	{
		feedback = "	You found the Hurkle!\n";
		hurkleGrid[X][Y] = "@";
		displayGrid();
		cout << feedback;
		return true;
	}
	else
	{
		if (hX == X)
		{
			feedback = "	Correct X co-ordinate\n";
		}
		else
		{
			if (hX - X > 0)
			{
				feedback = "	Too far South.\n";
			}
			else
			{
				feedback = "	Too far North.\n";
			}

		}

		if (hY == Y)
		{
			feedback += "	Correct Y coordinate\n";
		}
		else
		{
			if (hY - Y > 0)
			{
				feedback += "	Too far West\n";
			}
			else
			{
				feedback += "	Too far East\n";
			}
		}

		hurkleGrid[X][Y] = "*";
		displayGrid();
		cout << feedback;
		return false;
	}


}


void gameOver(bool found, int hX, int hY)
{
	hurkleGrid[hX][hY] = "@";
	displayGrid();

	if (found)
	{
		playerWins++;
		cout << "\tWell done, " + playerName + ".\n";
	}
	else
	{
		hurkleWins++;
		cout << "\tBad luck, " + playerName + ".\n";
	}

	cout << "\nPlayer Wins: " << playerWins << "\n";
	cout << "\nHurkle Wins: " << hurkleWins << "\n";

	string playAgain = askForString("Do you want to play again? (y/n): ");

	if (playAgain == "y" || playAgain == "Y")
	{
		waitForPlayer();
		playHurkle();
	}
	else
	{
		cout << "\nThanks for playing!\n";
		waitForPlayer();
	}
}

