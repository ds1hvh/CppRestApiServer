#pragma once

#include "Card.h"
#include <random>
#include <algorithm>
#include <vector>

class Board {

public :
	Board(int size);

	// ¼ÅÇÃ
	void shuffle();

	// Getter
	bool* getClearList();
	int getSize();

	// Guess card
	bool guess(int val);

	// Print board
	void printBoard();

	bool isClear();

protected :

private :
	std::vector<Card>	board;
	int					size;		
	int					clear_count;	
	int					card1_index;

};