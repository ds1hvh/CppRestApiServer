#pragma once

class Card {
	
public :

	Card();
	Card(int value);

	bool operator == (Card& card2);
	void clear();

	// Getter, setter
	void setValue(int value);
	
	bool getCleared();
	
	int getValue();

protected :

private : 
	bool cleared;
	int value;
};