#include <iostream>
#include "humanPlayer.h"


int humanPlayer::makeMove()
{
	int move;
	std::cout << "Bitte tätige deinen Zug "<<name<<": ";
	if (!(std::cin >> move)) { //cin has error --> input was not an integer
		std::cin.clear();
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
		std::cout << "\nUngültige Spalte, wähle bitte eine Zahl zwischen 1 und 7: ";
		makeMove();
	}
	else {
		if (move > 0 && move <= 7)
			return move;

		std::cout << "\nUngültige Spalte, wähle bitte eine Zahl zwischen 1 und 7: ";
		makeMove();
	}
}

	


humanPlayer::humanPlayer()
{
	std::cout << "Gebe deinen Namen ein: ";
	std::cin >> this->name;
	this->isHuman = true;
}

