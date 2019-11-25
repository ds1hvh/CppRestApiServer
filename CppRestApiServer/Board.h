#pragma once

#include "Card.h"
#include <random>
#include <algorithm>
#include <vector>

class Board {

public :
	Board(int len);

	// ����
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
	std::vector<Card>	board;			// 2���� �迭 ������
	int					len;			// ����
	int					card1_index;	// ù��°�� ������ ī��
};