#include "Suit.h"

#pragma once
class Card
{
public:
	// Initializes a Card object. Each card contains a Suit and face value.
	// Special Values defined as the follow: 
	// Ace - 1, Jack - 11, Queen - 12, King - 13
	Card(Suit suit, int face);

	// Returns the suit of the current card instance.
	Suit getSuit() const;

	// Returns the value of the current card instance.
	int getFaceValue() const;

	// Card destructor
	~Card();

protected:
	Suit suit;
	int face;

};

