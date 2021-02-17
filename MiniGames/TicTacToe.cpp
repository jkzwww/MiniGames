
#include "TicTacToe.h"

char playerPiece, compPiece, winnerPiece, player1Piece, player2Piece;
vector<char> board(9);
bool isGameOver;
int currentPlayer = 0;

void playOX(int playerNum)
{
	system("cls");
	displayText("TicTacToe.txt");
	waitForPlayer();

	if (playerNum == 1)
	{
		string goFirst = askForString("Do you want to play as X or O ?  ");
		setGamePiece(goFirst);
		resetBoard();

		isGameOver = false;

		while (!isGameOver)
		{
			if (currentPlayer == 0)
			{
				humanMove();
				displayBoard();
			}
			else if (currentPlayer == 1)
			{
				computerMove();
				displayBoard();
			}

			isGameOver = checkGameOver();

			currentPlayer = swapPlayers(currentPlayer,2);
		}

	}
	else
	{
		string gamePieceChoice = askForString("Player 1, do you want to play as X or O ?  ");
		setMultiPlayerPiece(gamePieceChoice);
		resetBoard();

		isGameOver = false;

		while (!isGameOver)
		{
			playerMove(currentPlayer);

			displayBoard();

			isGameOver = checkGameOver();

			currentPlayer = swapPlayers(currentPlayer, 2);
		}
	}

	waitForPlayer();
	displayBoard();
	gameOver(playerNum);

	string replay = askForString("Do you want to play again? (y/n) : ");
	if (replay != "n")
	{
		playOX(playerNum);
	}

}


void setGamePiece(string letter)
{
	if (letter == "x" | letter == "X")
	{
		playerPiece = 'X';
		compPiece = 'O';
		currentPlayer = 0;

		cout << "\n You'll go first \n";
	}
	else
	{
		playerPiece = 'O';
		compPiece = 'X';
		currentPlayer = 1;

		cout << "\n You'll go after \n";
	}
}


void setMultiPlayerPiece(string gamePieceChoice)
{
	if (gamePieceChoice == "x" | gamePieceChoice == "X")
	{
		player1Piece = 'X';
		player2Piece = 'O';
		currentPlayer = 0;

		cout << "\n You'll go first, player 1 \n";
	}
	else
	{
		player1Piece = 'O';
		player2Piece = 'X';
		currentPlayer = 1;

		cout << "\n You'll go after player 2 \n";
	}
}

void resetBoard()
{
	for (unsigned int i = 0; i < board.size(); i++)
	{
		board[i] = NULL;
	}
}


void displayBoard()
{
	stringstream gameBoard;

	gameBoard << "\n\t\t+---+---+---+" << endl;
	gameBoard << "\t\t| " << board[0] << " | " << board[1] << " | " << board[2] << " | " << endl;
	gameBoard << "\t\t+---+---+---+" << endl;
	gameBoard << "\t\t| " << board[3] << " | " << board[4] << " | " << board[5] << " | " << endl;
	gameBoard << "\t\t+---+---+---+" << endl;
	gameBoard << "\t\t| " << board[6] << " | " << board[7] << " | " << board[8] << " | " << endl;
	gameBoard << "\t\t+---+---+---+\n" << endl;

	cout << gameBoard.str();
}


bool isMoveLegal(int location)
{
	if (board[location] == NULL)
	{
		return true;
	}
	else
	{
		return false;
	}
}


void playerMove(int currentPlayer)
{
	int move;
	do
	{
		cout << " Player " << currentPlayer + 1 << "'s turn~ " << endl;
		move = askForNumber("Where will you move? (0 to 8) : ", 0, 8);

	} while (!isMoveLegal(move));

	if (currentPlayer == 0)
	{
		board[move] = player1Piece;
	}
	else
	{
		board[move] = player2Piece;
	}

}


void humanMove()
{
	int move;
	do
	{
		move = askForNumber("Where will you move? (0 to 8) : ",0,8);

	} while (!isMoveLegal(move));

	cout << "Hmmm Let's see...\n";
	board[move] = playerPiece;

}


void computerMove()
{
	// Working with a copy of the board for testing possible moves
	// Computer AI is a basic 3-step strategy
	unsigned int move = 0;
	bool found = false;
	// 1: if the computer can win on this move
	while (!found && move < board.size()) 
	{
		if (isMoveLegal(move)) {
			board[move] = compPiece;
			found = checkGameOver();
			board[move] = NULL;
		}
		if (!found) {
			move++;
		}
	}
	// 2: if the human can win on next move, block them
	if (!found) {
		move = 0;
		while (!found && move < board.size()) {
			if (isMoveLegal(move)) {
				board[move] = playerPiece;
				found = checkGameOver();
				board[move] = NULL;
			}
			if (!found) {
				move++;
			}
		}
	}
	// 3: otherwise take best remaining square
	if (!found) {
		move = 0;
		unsigned int pos = 0;
		const int BEST_MOVES[] = { 4, 0, 2, 6, 8, 1, 3, 5, 7 };
		while (!found && pos < board.size()) {
			move = BEST_MOVES[pos];
			if (isMoveLegal(move))
			{
				found = true;
			}

			pos++;
		}
	}
	// display the result
	cout << "\n I shall take square number " << move << endl;
	board[move] = compPiece;
}


bool checkGameOver()
{

	vector<char>::iterator iter;
	string firstRow;
	firstRow.push_back(board[0]);
	firstRow.push_back(board[1]);
	firstRow.push_back(board[2]);

	string secondRow;
	secondRow.push_back(board[3]);
	secondRow.push_back(board[4]);
	secondRow.push_back(board[5]);

	string thirdRow;
	thirdRow.push_back(board[6]);
	thirdRow.push_back(board[7]);
	thirdRow.push_back(board[8]);

	string firstCol;
	firstCol.push_back(board[0]);
	firstCol.push_back(board[3]);
	firstCol.push_back(board[6]);

	string secondCol;
	secondCol.push_back(board[1]);
	secondCol.push_back(board[4]);
	secondCol.push_back(board[7]);

	string thirdCol;
	thirdCol.push_back(board[2]);
	thirdCol.push_back(board[5]);
	thirdCol.push_back(board[8]);

	string leftDiag;
	leftDiag.push_back(board[0]);
	leftDiag.push_back(board[4]);
	leftDiag.push_back(board[8]);

	string rightDiag;
	rightDiag.push_back(board[2]);
	rightDiag.push_back(board[4]);
	rightDiag.push_back(board[6]);


	if (firstRow == "XXX" || secondRow == "XXX" || thirdRow == "XXX" || firstCol == "XXX" || secondCol == "XXX" || thirdCol == "XXX" || leftDiag == "XXX" || rightDiag == "XXX")
	{
		winnerPiece = 'X';
		return true;
	}

	if (firstRow == "OOO" || secondRow == "OOO" || thirdRow == "OOO" || firstCol == "OOO" || secondCol == "OOO" || thirdCol == "OOO" || leftDiag == "OOO" || rightDiag == "OOO")
	{
		winnerPiece = 'O';
		return true;
	}

	if (count(board.begin(), board.end(), NULL) == 0)
	{
		winnerPiece = 'y';
		return true;
	}

	return false;
}

void gameOver(int numPlayer)
{
	if (numPlayer == 1)
	{
		if (playerPiece == winnerPiece)
		{
			cout << "\n\t Congrats!! ( ^ - ^ )/ You're the winner!!! \n\n";
		}
		else if (compPiece == winnerPiece)
		{
			cout << "\n\t Oops! (O ^ O)/ You've lost the game...\n\n";
		}
		else
		{
			cout << "\n\t It's a TIE !!! (O A O)/ \n\n";
		}
	}
	else
	{
		if (player1Piece == winnerPiece)
		{
			cout << "\n\t Congrats, player 1~!! ( ^ - ^ )/ You're the winner!!! \n\n";
			cout << "\n\t Oops!player 2~ (O ^ O)/ You've lost the game...\n\n";
		}
		else if (player2Piece == winnerPiece)
		{
			cout << "\n\t Congrats, player 2~!! ( ^ - ^ )/ You're the winner!!! \n\n";
			cout << "\n\t Oops!player 1~ (O ^ O)/ You've lost the game...\n\n";
		}
		else
		{
			cout << "\n\t It's a TIE !!! (O A O)/\n\t Good game for both of ya~ \n\n";
		}
	}

	waitForPlayer();
}