#pragma once
class TicTacToeGame
{
public:
	TicTacToeGame();

	void playGame();

	
private:
	

	int getXCoord();
	int getYCoord();
	bool placeMarker(int x, int y, char currentPlayer);

	bool checkForVictory(char currentPlayer);

	void clearBoard(); // empties the board
	void printBoard(); //prints the board
	char board[3][3];

};

