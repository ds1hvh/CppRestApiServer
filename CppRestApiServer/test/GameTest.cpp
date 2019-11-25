#include<iostream>
#include "../game/Board.h"

int gameTest() {

	Board b(5);
	int choice;

	while (!b.isClear()) {
		b.printBoard();
		std::cout << "¸î¹ø? : ";
		std::cin >> choice;
		b.guess(choice);

	}

	return 0;
}