
#include "Hangman.h"

vector <string> easyList;
vector <string> normalList;
vector <string> hardList;
const int WORDNUM = 10;

int playerWin = 0;
bool playAgain = true;
int difficulty;

void startHangman()
{
	//seed random
	srand(unsigned(time(NULL)));

	//rules
	displayText("hangman.txt");
	difficulty = askForNumber("Choose a difficulty, easy[0] normal[1] hard[2] : ",0,2);

	waitForPlayer();

	//initialize
	readData();

	while (playAgain)
	{
		playHangman();
	}
	
	cout << "\nHope you had fun~ :)\n\n";
	waitForPlayer();
}


void playHangman()
{
	string word = generateWord(difficulty);

	int guessLeft = 6;
	bool wordGuessed = false;

	string playerGuess = "";
	string wrongGuess = "";
	string halfSolved = generateGuessWord(word, playerGuess, "");

	while (guessLeft != 0 && !wordGuessed)
	{

		cout << "\n\nThe word you have to guess is : \n\t" << halfSolved << endl;

		cout << "\nThere are " << word.length() << " letters in this word.\n";

		cout << "You have " << guessLeft << " guesses left~\n";

		if (wrongGuess != "")
		{
			cout << "You have guessed: " << wrongGuess << endl;
		}

		playerGuess = askForString("\nGuess a letter or guess the word : ");

		if (playerGuess.length() > 1)
		{
			if (playerGuess != word)
			{
				cout << "\nWrong guess ~ (> o <)/ \n";
				guessLeft--;
			}
			else
			{
				wordGuessed = true;
			}
		}
		else
		{
			if (isLetterContained(word, playerGuess))
			{
				cout << "\nNice one~(^ w ^)/ \n";
			}
			else
			{
				cout << "\nWrong guess ~ (> o <)/ \n";
				guessLeft--;
				wrongGuess += playerGuess;
			}

			halfSolved = generateGuessWord(word, playerGuess, halfSolved);

			int unsolvedLetter = 0;
			for (int i = 0; i < halfSolved.length(); i++)
			{
				if (halfSolved[i] == '*')
				{
					unsolvedLetter++;
				}
			}

			if (unsolvedLetter == 0)
			{
				wordGuessed = true;
			}
		}

		system("cls");
		displayHangman(guessLeft);
	}

	system("cls");
	displayHangman(guessLeft);

	cout << "\n\nThe word is " << word << " \n";

	if (halfSolved == word || wordGuessed)
	{
		cout << "Well done getting it right!!!\nYou've saved the man~\n\n";
		playerWin++;
	}
	else
	{
		cout << "Too bad... You've ran out of chances and the man's dead...\n\n";
	}

	if (playerWin != 0 && difficulty != 2 && playerWin%3 == 0)
	{
		difficulty++;
	}

	string replay = askForString("Do you wanna continue playing? (y/n) : ");

	if (replay == "n" || replay == "N")
	{
		playAgain = false;
	}
}


void readData()
{

	//read in words
	ifstream fileToRead("hangmanWords.txt");

	if (fileToRead.is_open())
	{
		int wordcount = 0;
		string line = "";

		while (!fileToRead.eof())
		{
			getline(fileToRead, line, '\n');
			wordcount++;

			if (wordcount <= WORDNUM)
			{
				easyList.push_back(line);
			}
			else if (wordcount <= WORDNUM * 2)
			{
				normalList.push_back(line);
			}
			else
			{
				hardList.push_back(line);
			}
		}
	}
	else
	{
		cout << "\n		File not found.\n";
	}

}


void displayHangman(int guessleft)
{		

	string hangman0 = "_____________\n";
	string hangman1 = "|    }       \n";
	string hangman2 = "|    O       \n";
	string hangman3 = "|    |       \n";
	string hangman4 = "|  / | \\    \n";
	string hangman5 = "| /  |  \\   \n";
	string hangman6 = "|   / \\     \n";
	string hangman7 = "|  /   \\    \n";
	string hangman8 = "|            \n";
	string hangman9 = "|____________\n";

	switch(guessleft)
	{
	case 1:
		hangman7.erase(1, 11);
		break;

	case 2:
		hangman7.erase(1, 11);
		hangman6.erase(1, 11);
		break;

	case 3:
		hangman7.erase(1, 11);
		hangman6.erase(1, 11);
		hangman5.erase(1, 11);
		break;

	case 4:
		hangman7.erase(1, 11);
		hangman6.erase(1, 11);
		hangman5.erase(1, 11);
		hangman4.erase(1, 11);
		break;

	case 5:
		hangman7.erase(1, 11);
		hangman6.erase(1, 11);
		hangman5.erase(1, 11);
		hangman4.erase(1, 11);
		hangman3.erase(1, 12);
		break;

	case 6:
		hangman7.erase(1, 11);
		hangman6.erase(1, 11);
		hangman5.erase(1, 11);
		hangman4.erase(1, 11);
		hangman3.erase(1, 12);
		hangman2.erase(1, 12);
		break;
	}

	cout << hangman0 << hangman1 << hangman2 << hangman3 << hangman4 << hangman5 << hangman6 << hangman7 << hangman8 << hangman9 << endl;

}


string generateWord(int difficulty)
{
	int index = rand() % WORDNUM;

	string word;

	switch (difficulty)
	{
	case 0: 
		word = easyList[index];
		break;

	case 1:
		word = normalList[index];
		break;

	case 2:
		word = hardList[index];
		break;
	}

	return word;
}


string generateGuessWord(string word, string letter, string halfSolved)
{
	string guessword;

	if (letter == "")
	{
		for (int i = 0; i < word.length(); i++)
		{
			guessword += "*";
		}
	}
	else
	{

		guessword = halfSolved;

		for (int i = 0; i < word.length(); i++)
		{
			if (word[i] == letter[0])
			{
				guessword[i] = letter[0];
			}
		}
	}
	

	return guessword;
}


bool isLetterContained(string word, string letter)
{
	for (int i = 0; i < word.length(); i++)
	{
		if (word[i] == letter[0])
		{
			return true;
		}
	}

	return false;
}