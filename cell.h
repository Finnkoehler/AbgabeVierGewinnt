#pragma once
#include <array>
#include "utils.h"
#include <iostream>
class cell
{
public:
	std::array <cell*, 8> neighbours{ nullptr };
	cellState state;
	cell() {};
	cell(cellState s);
	bool checkWin();
	int checkNeighbour(int,bool);
	bool lastMove;
	bool winStreak;
	friend std::ostream& operator<<(std::ostream& os, const cell& cell) {
		os << int(cell.state);
		return os;
	}
};

