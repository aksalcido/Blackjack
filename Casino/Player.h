#ifndef PLAYER_H
#define PLAYER_H

#include <iostream>
#include "Hand.h"

class Player
{
public:
	// Default Constructor
	Player();

	// Initializes a Player parent class. Player is the parent for any class that participates in games. 
	// (e.g User, Dealer, AI, etc)
	Player(int funds);

	// Player copy constructor
	Player(const Player& p);

	// Adds the Card* argument to the hand of the player.
	void addCardToHand(Card* card);

	// Clears the entire hand of the current player.
	void clearHand();

	// Adds 'extra' to the current funds of the Player.
	void addFunds(int extra);

	// Removes 'loss' from the current funds of the Player.
	void decreaseFunds(int loss);

	// Returns the total funds of the player.
	int getFunds() const;

	// Returns the current Hand of the player.
	Hand getHand() const;

	~Player();

protected:
	int funds;
	Hand hand;
};


#endif // PLAYER_H