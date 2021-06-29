#include "controller.h"
#include "computerPlayer.h"
#include "humanPlayer.h"
#include <Windows.h>
#include <iostream>
HANDLE hConsole2 = GetStdHandle(STD_OUTPUT_HANDLE);

controller::controller() {
	int temp;
	std::cout << "Um gegen einen weiteren Spieler zu spielen gebe 1 ein. Um gegen einen Computer zu spielen geben 2 ein.." << std::endl;
	std::cin >> temp;
	p[0] = new humanPlayer();
	//p[0] = new computerPlayer();
	if (temp == 1)
		p[1] = new humanPlayer();
	else if (temp == 2)
		p[1] = new computerPlayer();
	f = field();
	r = renderer(&f);
	std::cout << p[0]->getName() << " hat Farbe";
	SetConsoleTextAttribute(hConsole2, 11);
	std::cout << " blau\n";
	SetConsoleTextAttribute(hConsole2, 15);
	std::cout << p[1]->getName() << " hat Farbe";
	SetConsoleTextAttribute(hConsole2, 12);
		std::cout << " rot";
	SetConsoleTextAttribute(hConsole2, 15);
	startGame();
}

void controller::startGame() {
	bool isWin = false;
	int freeCells = f.getCellCount();
	int nextPlayer = 0;
	cell* c=nullptr;
	cell* c2=nullptr; //Pointer auf letzte Zelle
	while (!isWin && freeCells > 0)
	{
		bool wrongMove = false;
		std::cout << std::endl;
		r.renderField();
		std::cout << std::endl;
		do {
			if (wrongMove) {
				if (p[nextPlayer % 2]->getIsHuman()) {
					std::cout << "Spalte ist bereits voll. Bitte wähle eine andere...\n";
				}
			}
			c = f.getEntry(p[nextPlayer % 2]->makeMove());
			wrongMove = true;
		} while (c == nullptr);

		f.makeEntry(c, nextPlayer);
		if(c2!=nullptr)
			c2->lastMove = false;
		c->lastMove = true;
		c2 = c;
		if (checkWin(c)) {
			isWin = true;
		}
		else {
			freeCells--;
			nextPlayer++;
		}
	}
	if (isWin) {
		r.renderField();
		c->lastMove = false;
		r.renderField();
		std::cout <<"\n"<< p[nextPlayer % 2]->getName() << " hat gewonnen!\n";
	}
	else {
		std::cout << "Unentschieden!\n";
	}
}

bool controller::checkWin(cell* c)
{
	return c->checkWin();
}

