#ifndef DEALER_H
#define DEALER_H

#pragma once
#include "Player.h"
#include "Deck.h"
#include <iostream>


class Dealer : public Player
{
public:
	// Initializes a dealer that inherits from the Player class. This represents your opponent in each game.
	// Dealers can not go bankrupt, and own a deck of cards to deal to each player.
	Dealer(int funds);
	
	// Copy constructor for Dealer
	Dealer(const Dealer& b);

	// Deals the remaining cards to themselves based on their current score.
	void dealRemainingCards();

	// Resets the deck and shuffles it and called after a round ends in preparation for the next round
	void resetAndShuffle();
	
	// Debugger Function to display the content of the Dealer's deck.
	void displayDeck();

	// Returns a pointer to a card that is dealt from the top of the deck.
	Card* dealCard();

	// Dealer destructor
	~Dealer();

private:
	Deck deck;
};

#endif // DEALER_H
