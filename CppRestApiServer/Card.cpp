#include "Card.h"

Card::Card() 
{
	cleared = false;
	value = 0;
}

Card::Card(int value) 
{
	cleared = false;
	this->value = value;
}

bool Card::operator == (Card& card2)
{
	if (this->value == card2.value) 
	{
		return true;
	}

	return false;
}

void Card::clear() 
{
	this->cleared = true;
}

void Card::setValue(int value)
{
	this->value = value;
}

bool Card::getCleared()
{
	return cleared;
}

int Card::getValue()
{
	return value;
}