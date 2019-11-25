#pragma once

#include "Card.h"
#include <random>
#include <algorithm>
#include <vector>

class Board {

public :
	Board(int len);

	// 셔플
	void shuffle();

	// Getter
	bool* getBoard();
	int getLen();

	// Guess card
	void guess(int val);

	// Print board
	void printBoard();

protected :

private :
	std::vector<Card>	board;			// 2차원 배열 보드판
	int					len;			// 길이
	int					card1_index;	// 첫번째로 뒤집는 카드
};