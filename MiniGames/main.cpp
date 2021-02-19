
#include "main.h"

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
	case 1:
		singleMenu();
		break;

	case 2:
		multiMenu();
		break;

	case 3:
		displayText("aboutUs.txt");
		waitForPlayer();
		mainMenu();
		break;
		
	case 0:
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

	case 1:
		playOX(1);
		mainMenu();
		break;

	case 2:
		startHurkle();
		mainMenu();
		break;

	case 3:
		startHangman();
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

	case 1:
		playOX(2);
		mainMenu();
		break;

	case 2:
		startPiggy();
		mainMenu();
		break;

	case 3:
		startEvenMinusOdd();
		mainMenu();
		break;
	}
}