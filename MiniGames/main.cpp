
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
	
	int choice = askForNumber("\nPlease enter your option: ",0,2);

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
		
	}

}


void singleMenu()
{
	displayText("singleMenu.txt");

	int choice = askForNumber("\nPlease select a game: ", 0, 3);

	switch (choice)
}


void multiMenu()
{
	displayText("multiMenu.txt");
}