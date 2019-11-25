#include "Card.h"

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