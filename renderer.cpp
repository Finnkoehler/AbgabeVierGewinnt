#include "renderer.h"
#include <iostream>
#include <string>
#include <Windows.h>
#include "utils.h"
HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
renderer::renderer(field* f)
{
	fieldmodel = f;
}
void renderer::renderField()
{
	std::cout << "\t";
	SetConsoleTextAttribute(hConsole, 7);
	for (int i = 0; i < 7; i++)
		std::cout << i + 1 << "\t";
	std::cout << std::endl;
	std::cout << "    ";
	for (int i = 0; i < 7; i++)
		std::cout << "--------";
	std::cout << std::endl;
	SetConsoleTextAttribute(hConsole, 15);
	int zeile = 1;
	for (int i = 5; i >= 0; i--)
	{
		std::cout<< zeile;
		for (int j = 0; j < 7; j++)
		{
			cell c = fieldmodel->getPlayground().at(j).at(i);
			std::cout << "   |   ";
			if (c.state == cellState::player1) {
				if (c.winStreak) {
					SetConsoleTextAttribute(hConsole, 28);
				}
				else {
					SetConsoleTextAttribute(hConsole, 50);
				}
			}
			else if (c.state == cellState::player2) {
				if (c.winStreak) {
					SetConsoleTextAttribute(hConsole, 93);
				}
				else {
					SetConsoleTextAttribute(hConsole, 204);
				}
			}
			if (c.lastMove) {
				SetConsoleTextAttribute(hConsole, 10);
			}
			std::cout << c ;
			SetConsoleTextAttribute(hConsole, 15);
	
		}
		std::cout << "   |";
		zeile++;
		std::cout << std::endl;
	}
}