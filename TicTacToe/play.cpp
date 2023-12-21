#include "play.h"
#include <iostream>
using namespace std;

char board[3][3];

void resetBoard() {
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			board[i][j] = ' ';
		}
	}
}

void printBoard() {
	cout << board[0][0] << " | " << board[0][1] << " | " << board[0][2] << endl;
	cout << "--|---|--" << endl;
	cout << board[1][0] << " | " << board[1][1] << " | " << board[1][2] << endl;
	cout << "--|---|--" << endl;
	cout << board[2][0] << " | " << board[2][1] << " | " << board[2][2] << endl;
}

int checkFreeSpaces() {
	int free_spaces = 9;
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			if (board[i][j] != ' ') {
				free_spaces--;
			}
		}
	}
	return free_spaces;
}

void player1Move() {
	int x;
	int y;

	do
	{
		cout << "Player 1: " << endl;
		cout << "Enter row number (1-3): " << endl;
		cin >> x;
		x--;
		cout << "Enter column number (1-3): " << endl;
		cin >> y;
		y--;

		if (board[x][y] != ' ') {
			cout << "Invalid move!" << endl;
		}
		else {
			board[x][y] = PLAYER1;
			break;
		}
	} while (board[x][y] != ' ');
}

void player2Move() {
	int x;
	int y;

	do
	{
		cout << "Player 2: " << endl;
		cout << "Enter row number (1-3): " << endl;
		cin >> x;
		x--;
		cout << "Enter column number (1-3): " << endl;
		cin >> y;
		y--;

		if (board[x][y] != ' ') {
			cout << "Invalid move!" << endl;
		}
		else {
			board[x][y] = PLAYER2;
			break;
		}
	} while (board[x][y] != ' ');
}

char checkWinner() {
	//check columns
	for (int i = 0; i < 3; i++) {
		if (board[i][0] == board[i][1] && board[i][1] == board[i][2]) {
			return board[i][0];
		}
	}
	//check rows
	for (int j = 0; j < 3; j++) {
		if (board[0][j] == board[1][j] && board[1][j] == board[2][j]) {
			return board[0][j];
		}
	}
	//check diagonals
	if ((board[0][0] == board[1][1] && board[1][1] == board[2][2]) || (board[2][0] == board[1][1] && board[1][1] == board[0][2])) {
		return board[1][1];
	}
	return ' ';
}

void gameOver(char winner) {
	if (winner == PLAYER1) {
		cout << "Player 1 has won the game!" << endl;
	}
	else if (winner == PLAYER2) {
		cout << "Player 2 has won the game!" << endl;
	}
	else {
		cout << "It's a tie!" << endl;
	}
}

