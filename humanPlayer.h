#pragma once
#include "player.h"
class humanPlayer : public player
{
public:
	humanPlayer();
	int makeMove() override;
};

