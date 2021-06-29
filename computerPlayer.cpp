#include <random>

#include "computerPlayer.h"


computerPlayer::computerPlayer()
{
	name = "Computer";
	this->isHuman = false;
}

int computerPlayer::makeMove() {
	std::random_device rd;
    std::mt19937 mt(rd());
    std::uniform_int_distribution<int> dist(1, 7);
	return dist(mt);
}