#pragma once
#include <string>

class player
{
protected:
	std::string name;
	bool isHuman;
public:
	std::string getName() {
		return this->name;
	}

	virtual int makeMove() = 0;
	bool getIsHuman() { return this->isHuman; }
};

