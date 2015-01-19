#include "TicTacToeGame.h"
#include <iostream>

using namespace std;


TicTacToeGame::TicTacToeGame()
{
	
}

void TicTacToeGame::playGame(){

	clearBoard();

	char player1 = 'X';
	char player2 = 'O';

	char currentPlayer = player1;

	bool isDone = false;
	int x, y;

	int turn = 0;

	while (isDone == false) {


		printBoard();

		x = getXCoord();
		y = getYCoord();

		if (placeMarker(x, y, currentPlayer) == false){
			cout << "That spot is occupied!\n";

		}
		else {
			turn++;
			if (checkForVictory(currentPlayer) == true) {
				cout << "The game is over! Player " << currentPlayer << " has won!\n";
					isDone = true;
			}
			else if (turn == 9) {
				cout << "It's a tie game!\n";
				isDone == true;
			}
			//switch players
			if (currentPlayer == player1) {
				currentPlayer = player2;
			}
			else {
				currentPlayer = player1;
			}
		}
	}


}



int TicTacToeGame::getXCoord() { //find the x coord
	int x;
	bool isInputBad = true;


	while (isInputBad == true){

		cout << "Enter the X coordinate: ";
		cin >> x;
		if (x < 1 || x > 3){
			cout << "Invalid Co-ordinate\n";

		}
		else {
			isInputBad = false;
		}

		return x - 1;
	}
}
int TicTacToeGame::getYCoord() { // find the y coord
	int y;
	bool isInputBad = true;


	while (isInputBad == true) {


		cout << "Enter the Y coordinate: ";
		cin >> y;
		if (y < 1 || y > 3){
			cout << "Invalid Co-ordinate\n";

		}
		else {
			isInputBad = false;
		}
		return y - 1;
	}
}

bool TicTacToeGame::placeMarker(int x, int y, char currentPlayer)
{
	if (board[y][x] != ' ') {
		return false;

	}
	board[y][x] = currentPlayer;
	return true;
}

bool TicTacToeGame::checkForVictory( char currentPlayer){
	//check the rows 
	for (int i = 0; i < 3; i++) {
		if ((board[i][0] == currentPlayer) && (board[i][0] == board[i][1]) && (board[i][1] == board[i][2])) {
			return true; // we won!
		}
	}
	for (int i = 0; i < 3; i++) {
		if ((board[0][i] == currentPlayer) && (board[0][i] == board[1][i]) && (board[1][i] == board[2][i])) {
			return true; // we won!
		}
	}
	//check top left
	if ((board[0][0] == currentPlayer) && (board[0][0] == board[1][1]) && (board[1][1] == board[2][2])){
		return true;
	}
	//check top right diagnol
	if ((board[2][0] == currentPlayer) && (board[2][0] == board[1][1]) && (board[1][1] == board[0][2])){
		return true;
	}
	return false;
}

void TicTacToeGame::clearBoard() {

	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			board[i][j] = ' ';

		}

	}

}
void TicTacToeGame::printBoard() {
	
	cout << endl;
	cout << " |1 2 3|\n";
	for (int i = 0; i < 3; i++) {
		cout << "--------\n";
		cout << i+1<< "|" << board[i][0] << "|" << board[i][1] << "|" << board[i][2] << "|\n";
	}
	cout << "--------\n";

}