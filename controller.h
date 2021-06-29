#pragma once

#include <array>

#include "player.h"
#include "field.h"
#include "renderer.h"

class controller
{
private:
	std::array<player*, 2> p;
	field f;
	renderer r;

public:
	void startGame();
	bool checkWin(cell*);
	controller();
	//~controller();
};

