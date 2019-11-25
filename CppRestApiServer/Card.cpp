#include "Card.h"

bool Card::operator == (Card& card2)
{
	if (this->value == card2.value) 
	{
		return true;
	}

	return false;
}

void Card::setCleared(bool cleared) 
{
	this->cleared = cleared;
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