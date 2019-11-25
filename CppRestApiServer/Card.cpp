#include "Card.h"

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