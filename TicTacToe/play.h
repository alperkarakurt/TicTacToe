const char PLAYER1 = 'X';
const char PLAYER2 = 'O';
void resetBoard();
void printBoard();
int checkFreeSpaces();
void player1Move();
void player2Move();
char checkWinner();
void gameOver(char winner);