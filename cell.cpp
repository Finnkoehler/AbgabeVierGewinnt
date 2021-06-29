#include "cell.h"
cell::cell(cellState s)
{
	lastMove = false;
	winStreak = false;
	state = s;
}

bool cell::checkWin(){
	for (int i = 0; i < 4; i++) {
		int win = 1;
		win += this->checkNeighbour(i,false);
		win += checkNeighbour(i + 4, false);
		if (win >= 4) {
			checkNeighbour(i, true);
			checkNeighbour(i + 4, true);
			return true;
		}
	}
	return false;
}

int cell::checkNeighbour(int d, bool setStreak)
{
	if (setStreak) {
		winStreak = true;
	}
	if (neighbours[d] != nullptr)
		if (this->state == neighbours.at(d)->state) {
			return 1 + neighbours[d]->checkNeighbour(d,setStreak);
		}
	return 0;
}