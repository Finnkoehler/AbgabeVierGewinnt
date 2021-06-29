#pragma once

#include "player.h"
#include <random>


class computerPlayer : public player
{
private:

public:
    computerPlayer();
    int makeMove();
};

