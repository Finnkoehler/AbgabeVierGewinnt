#pragma once
#include "cell.h"
#include <vector>
class field
{
private:
	std::array<std::array<cell, 6>, 7> playground;
	void setCellNeighbours();
public:
	field(); 
	void clearField();
	cell* getEntry(int);
	void makeEntry(cell*,int);
	int getCellCount();
	std::array<std::array<cell, 6>, 7> getPlayground();
};

