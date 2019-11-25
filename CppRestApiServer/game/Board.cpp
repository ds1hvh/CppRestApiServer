#include "Board.h"
#include "Card.h"
#include <iostream>
#define NOCARD -1


Board::Board(int size) {
	this->size = size;
	card1_index = NOCARD;
	clear_count = 0;

	for (int i = 0; i < size; i++)
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
	std::random_device rd;
	std::mt19937 g(rd());

	std::shuffle(board.begin(), board.end(), g);
}

// Getter
bool* Board::getClearList()
{
	bool* answer = new bool[size];
	for (bool is_clear : board.)
	{
		answer[i] = false;
	}
	
	return answer;

}
int Board::getSize()
{
	return size;
}

// Guess card
bool Board::guess(int index)
{

	if (card1_index != NOCARD)
	{
		if (board[card1_index] == board[index]) 
		{
			board[card1_index].clear();
			board[index].clear();
			clear_count++;
		}

		card1_index = NOCARD;
	}
	else
	{
		card1_index = index;
	}

	return isClear();
}

void Board::printBoard() {
	for (int i = 0; i < board.size(); i++) {
		std::cout << i << ": " << board.at(i).getValue() << " " << board.at(i).getCleared() << std::endl;
	}
}

bool Board::isClear() 
{
	if (clear_count == size) 
	{
		return true;
	}

	return false;
}