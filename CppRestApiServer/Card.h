#pragma once

class Card {
	
public :

	Card() {
		cleared = false;
		value = 0;
	}

	bool operator == (Card& card2);

	// Getter, setter
	void setCleared(bool cleared);
	void setValue(int value);
	bool getCleared();
	int getValue();

protected :

private : 
	bool cleared;
	int value;
};