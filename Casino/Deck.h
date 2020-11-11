#ifndef DECK_H
#define DECK_H

#include <iostream>
#include <vector>
#include <algorithm>
#include <random>

#include "Card.h"

constexpr int DECK_SIZE = 52;

class Deck
{
public:
	// Initialize the Deck object. The initializer creates a new deck with the newDeck() function and then shuffles the deck.
	Deck();

	// Deck copy constructor
	Deck(const Deck& d);

	// Returns a pointer to a card on the top of the deck and increments the currentIndex.
	Card* top();

	// Shuffles the deck of cards
	void shuffle();

	// Restarts the deck by changing the currentIndex pointer to the beginning (0)
	void restart();

	// Displays the entirity of the deck to the User.
	void displayDeck() const;

	// Initializes a new deck
	void newDeck();

	// Destructor for the deck.
	~Deck();

private:
	std::vector<Card*> deck;
	int currentIndex;
};

#endif // DECK_H