#ifndef USER_H
#define USER_H

#pragma once
#include <iostream>
#include <string>
#include "Player.h"

class User : public Player
{
public:
	// Initializes a User Object. Represents the Primary User of the application while playing games.
	// Inherits from the Player Object to contain funds and a Hand of cards. User can go bankrupt, other Players can not (like the dealer).
	User(int funds);

	// User copy constructor
	User(const User& u);

	// Returns an int representing the user's bet. The bet must be within the fund limit.
	int getBetInput();

	// Returns a string of the user's move: 'hit' || 'fold'
	std::string getMoveInput();

	// Returns a boolean True if the user's funds become <= 0. False otherwise.
	bool bankrupt();

	// User Destructor
	~User();

private:
	// Validates the bet input made by the User -- If not enough or bad input -> returns false.
	bool validateBet();

	// Validates the move input made by the User -- Must be 'Hit' || 'Fold'
	bool validateInput();
};

#endif // USER_H