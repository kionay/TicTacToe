#include "pch.h"
#include <iostream>
//#include <stdlib.h>
#include <windows.h>   // WinApi header
#include <string>

/*How to change text color: https://stackoverflow.com/questions/4053837/colorizing-text-in-the-console-with-c */

using namespace std;
HANDLE  hConsole;

char gameBoard[3][3] = { {'1', '2', '3'},
						 {'4', '5', '6'},
						 {'7', '8', '9'} };
int scores[3] = { 0,0,0 }; //Xwins, Owins, Draws

bool playerXturn = true;

//Global color variables 
enum colors { blue = 9, green, teal, red, pink, yellow, white };
colors xColor = blue;
colors oColor = green;
colors sysColor = white;

//Prototypes
void drawGameBoard();

void colorText(string in, colors color) {
	hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

	SetConsoleTextAttribute(hConsole, color);
	cout << in;
	SetConsoleTextAttribute(hConsole, sysColor);
}
void colorText(char in, colors color) {
	string sIn = " ";
	sIn[0] = in;
	colorText(sIn, color);
}

void resetGame() {
	char number = '1';
	for (int row = 0; row < 3; row++) {
		for (int col = 0; col < 3; col++) {
			gameBoard[row][col] = number;
			number++;
		}
	}
}

void processPlayerInput(bool recursed) {
	char player = (playerXturn) ? 'X' : 'O';

	if (recursed) {
		drawGameBoard();
		cout << endl;
		colorText("Invalid Selection, Please Try Again.", red);
		cout << endl;
	}
	else {
		cout << endl << endl;
	}

	cout << "Player ";
	colorText(player, (playerXturn) ? xColor : oColor);
	cout << " Select a square, then press enter: ";
	char input;
	cin >> input;

	//Loop through the board matrix to locate a match
	//if no match then assume invalid input
	//otherwise update the matrix with player symbol
	bool valid = false;
	for (int row = 0; row < 3; row++) {
		for (int col = 0; col < 3; col++) {
			if (gameBoard[row][col] == input) {
				gameBoard[row][col] = player;
				valid = true;
				break;
			}
		}
		if (valid) { break; }
	}

	//If no matches were found in the matrix, ask again for input
	if (!valid) { processPlayerInput(true); }

	//Toggle to the other player's turn, but only from the root function
	if (!recursed) { playerXturn = !playerXturn; }
}

bool checkForWinners() {
	char winningPlayer = NULL;

	//Check all rows and columns
	for (int i = 0; i < 3; i++) {
		//check row i
		if (gameBoard[i][0] == gameBoard[i][1] && gameBoard[i][1] == gameBoard[i][2]) {
			winningPlayer = gameBoard[i][0];
		}
		//check col i
		if (gameBoard[0][i] == gameBoard[1][i] && gameBoard[1][i] == gameBoard[2][i]) {
			winningPlayer = gameBoard[0][i];
		}
	}
	//Check the diagonals (1,1 is the center of the board)
	if ((gameBoard[1][1] == gameBoard[0][0] && gameBoard[1][1] == gameBoard[2][2]) ||
		(gameBoard[1][1] == gameBoard[2][0] && gameBoard[1][1] == gameBoard[0][2])) {

		winningPlayer = gameBoard[1][1];
	}

	//Check for a cat game (no one won and all spaces selected)
	bool catGame = true; //assume no one won unless proven otherwise
	for (int row = 0; row < 3; row++) {
		for (int col = 0; col < 3; col++) {
			if (gameBoard[row][col] <= '9') {
				catGame = false;
			}
		}
	}

	if (winningPlayer && !catGame) {
		cout << endl << endl;
		cout << winningPlayer << " Won!!" << endl << endl;
		if (winningPlayer == 'X') {
			scores[0] += 1;
		}
		else {
			scores[1] += 1;
		}
		return true;
	}
	else {
		if (catGame) {
			cout << endl << endl;
			cout << "Cat game, No winners" << endl << endl;
			scores[2] += 1;
			return true;
		}
		else {
			return false;
		}

	}
}

void drawGameBoard() {
	system("CLS");
	colors playerColor;

	cout << "X Wins: " << scores[0] <<
		"    O Wins: " << scores[1] <<
		"     Draws: " << scores[2] << endl << endl;

	string boardShifter = "         ";
	for (int row = 0; row < 3; row++) {
		cout << boardShifter << "  ";
		for (int col = 0; col < 3; col++) {
			//Pick the color to show
			switch (gameBoard[row][col]) {
			case 'X':
				playerColor = xColor;
				break;
			case 'O':
				playerColor = oColor;
				break;
			default:
				playerColor = sysColor;
			}

			colorText(gameBoard[row][col], playerColor);
			if (col < 2) { cout << "  |  "; }
		}
		cout << endl;

		if (row < 2) { cout << boardShifter << "-----+-----+-----" << endl; }
	}

	/*
	  1  |  2  |  3
	-----+-----+-----
	  4  |  5  |  6
	-----+-----+-----
	  7  |  8  |  9
	*/


}
void swap(char& a, char& b) {
	char temp = a;
	a = b;
	b = temp;
}


void playGame() {
	drawGameBoard();
	processPlayerInput(false);
	

	if (checkForWinners()) {
		system("Pause");
		resetGame();
		drawGameBoard();
	}
}

int main() {
	while (1) {
		playGame();
	}
	return 0;
}