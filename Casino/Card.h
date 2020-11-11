#ifndef CARD_H
#define CARD_H

#include <string>
#include "Suit.h"

class Card
{
public:
	// Initializes a Card object. Each card contains a Suit and face value.
	// Special Values defined as the follow: 
	// Ace - 1, Jack - 11, Queen - 12, King - 13
	Card(Suit suit, int face, std::string name);

	// Returns the suit of the current card instance.
	Suit getSuit() const;

	// Returns the value of the current card instance.
	int getFaceValue() const;

	std::string getName() const;

	// Card destructor
	~Card();

private:
	Suit suit;
	int face;
	std::string name;

};

#endif // CARD_H