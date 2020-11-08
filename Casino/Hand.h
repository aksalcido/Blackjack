#ifndef HAND_H
#define HAND_H

#pragma once
#include <vector>
#include "Card.h"


class Hand
{
public:
	// Initializes a Hand object that is the container for the cards of each Player.
	// Typically around 5 cards but depending on the game can be more.
	Hand(int maxCards = 5);

	// Clears the current hand by clearing the hand vector.
	void clear();

	// Adds the Card* argument to the hand vector.
	void addCardToHand(Card* card);

	std::vector<Card*> getHand() const;

	~Hand();

protected:
	std::vector<Card*> hand;
};

#endif // HAND_H
