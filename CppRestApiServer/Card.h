#pragma once

class Card {
	
public :

	Card() {
		cleared = false;
		value = 0;
	}

	void setCleared(bool cleared);
	void setValue(int value);
	bool getCleared();
	int getValue();

protected :

private : 
	bool cleared;
	int value;
};