#include "Board.h"
#include "Card.h"
#include <iostream>
#define NOCARD -1


Board::Board(int len) {
	this->len = len;
	card1_index = NOCARD;

	for (int i = 0; i < len; i++) 
	{
		Card card(i), card2(i);
		board.push_back(card);
		board.push_back(card2);
	}
	
	shuffle();

}

// ¼ÅÇÃ
void Board::shuffle() 
{
	int size = len * 2;
	std::random_device rd;
	std::mt19937 g(rd());

	std::shuffle(board.begin(), board.end(), g);
}

// Getter
bool* Board::getBoard()
{
	bool* answer = new bool[5];
	for (int i = 0; i < 5; i++)
	{
		answer[i] = false;
	}
	
	return answer;

}
int Board::getLen()
{
	return len;
}

// Guess card
void Board::guess(int index)
{

	if (card1_index != NOCARD)
	{
		if (board[card1_index] == board[index]) 
		{
			board[card1_index].clear();
			board[index].clear();
		}

		card1_index = NOCARD;
	}
	else
	{
		card1_index = index;
	}

}

void Board::printBoard() {
	for (int i = 0; i < board.size(); i++) {
		std::cout << i << ": " << board.at(i).getValue() << std::endl;
	}
}