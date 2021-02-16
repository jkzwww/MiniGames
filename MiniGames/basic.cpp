
#include "basic.h"

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~display functions~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

void displayText(string myFileName)
{
	ifstream fileToRead(myFileName);

	if (fileToRead.is_open())
	{
		string line = "";

		while (!fileToRead.eof())
		{
			getline(fileToRead, line, ';');
			cout << line << "\n";

		}
	}
	else
	{
		cout << "\n	 File " << myFileName << " not found.\n";
	}
}


//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~QnA functions~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

string askForString(string question)
{
	string answer;

	cout << "\n" << question;
	getline(cin, answer, '\n');

	return answer;
}


int askForNumber(string question, int min, int max)
{
	string number;

	cout << "\n" << question;
	getline(cin, number, '\n');



	if (number != "" && stoi(number) >= min && stoi(number) <= max)
	{
		return stoi(number);
	}
	else
	{
		cout << "\n	invalid number!! \n";

		int newNum = askForNumber(question,min,max);
		if (newNum >= min && newNum <= max)
		{
			return newNum;
		}

	}

}


//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~Player functions~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

void waitForPlayer()
{
	system("pause");
	system("cls");
}


int swapPlayers(int currentPlayer,int numPlayers)
{
	currentPlayer++;

	if (currentPlayer == numPlayers)
	{
		currentPlayer = 0;
	}

	return currentPlayer;
}