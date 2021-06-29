#include "field.h"
#include "utils.h"
#include <array>
#include <iostream>
#include <stdexcept>

void field::setCellNeighbours()
{
	for (int i = 0; i < 7; i++)
	{
		for (int j = 0; j < 6; j++)
		{
			playground[i][j].neighbours[0] = (i > 0 && j < 5) ? &playground.at(i - 1).at(j + 1) : nullptr;
			playground[i][j].neighbours[1] = (j < 5) ? &playground.at(i).at(j + 1) : nullptr;
			playground[i][j].neighbours[2] = (i < 6 && j < 5) ? &playground.at(i + 1).at(j + 1) : nullptr;

			playground[i][j].neighbours[3] = (i < 6) ? &playground.at(i + 1).at(j) : nullptr;
			playground[i][j].neighbours[4] = (i < 6 && j > 0) ? &playground.at(i + 1).at(j - 1) : nullptr;

			playground[i][j].neighbours[5] = (j > 0) ? &playground.at(i).at(j - 1) : nullptr;
			playground[i][j].neighbours[6] = (j > 0 && i > 0) ? &playground.at(i - 1).at(j - 1) : nullptr;
			playground[i][j].neighbours[7] = (i > 0) ? &playground.at(i - 1).at(j) : nullptr;
		}
	}
}

field::field()
{
	field::clearField();
	field::setCellNeighbours();
}

void field::clearField()
{
	for (int i = 0; i < 7; i++)
	{
		for (int j = 0; j < 6; j++)
		{
			playground.at(i).at(j) = cell(cellState::empty);
		}
	}
}

cell* field::getEntry(int column)
{
	for (int i = 0; i < 6; i++) {
		if (playground[column - 1][i].state == cellState::empty) {
			return &playground[column - 1][i];
		}
	}
	return nullptr;
}

void field::makeEntry(cell* c, int nextPlayer)
{
	if (nextPlayer % 2 == 0)
		c->state = cellState::player1;
	else
		c->state = cellState::player2;
	setCellNeighbours();
}


int field::getCellCount() {
	return playground.max_size() * playground[0].max_size();
}

std::array<std::array<cell, 6>, 7> field::getPlayground()
{
	return this->playground;
}
