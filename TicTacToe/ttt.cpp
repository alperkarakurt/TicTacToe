#include "play.h"
#include <iostream>
using namespace std;

int main()
{
	char winner = ' ';
	char response;
	do
	{
		winner = ' ';
		response = ' ';
		resetBoard();
		while (winner == ' ' && checkFreeSpaces() != 0) {
			printBoard();
			player1Move();
			winner = checkWinner();
			if (winner != ' ') {
				gameOver(PLAYER1);
				break;
			}
			if (checkFreeSpaces() == 0) {
				break;
			}
			printBoard();
			player2Move();
			winner = checkWinner();
			if (winner != ' ') {
				gameOver(PLAYER2);
				break;
			}
			winner = checkWinner();
		} 
		printBoard();
		gameOver(winner);
		cout << "Play again? (Y/N): " << endl;
		cin >> response;
		response = toupper(response);
	} while (response == 'Y');
}



