#include <iostream>
#include "TicTacToeGame.h"

using namespace std;

int main() {
	char input;
	bool isDone = false;

	TicTacToeGame game;
	
	while (isDone == false){
		
		game.playGame();

		cout << "Would you like to play again? (Y/N)\n";

		cin >> input;
		if (input == 'N' || input == 'n') {
			isDone = true;

		}
		else {
			isDone = false;
		}

	}

	

	system("PAUSE");
	return 0;
}