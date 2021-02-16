
#include "main.h"
#include "TicTacToe.h"

int main()
{

	mainMenu();

	waitForPlayer();
	return 0;
}


void mainMenu()
{
	displayText("mainmenu.txt");
	
	int choice = askForNumber("\nPlease enter your option: ",0,3);

	switch (choice)
	{
	case 0:
		singleMenu();
		break;

	case 1:
		multiMenu();
		break;

	case 2:
		displayText("aboutUs.txt");
		waitForPlayer();
		mainMenu();
		break;
		
	case 3:
		cout << "\nThank you for playing with ruri and rubi~! See you soon~!\n\n";
		break;
	}

}


void singleMenu()
{
	displayText("singleMenu.txt");

	int playerNum = 1;

	int choice = askForNumber("Please select a game: ", 0, 3);

	switch (choice)
	{
	case 0:
		waitForPlayer();
		mainMenu();
		break;
	}
}


void multiMenu()
{
	displayText("multiMenu.txt");

	int playerNum = 2;

	int choice = askForNumber("Please select a game: ", 0, 3);

	switch (choice)
	{
	case 0:
		waitForPlayer();
		mainMenu();
		break;
	}
}