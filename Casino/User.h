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

	User(const User& u);

	int getBetInput();

	std::string getMoveInput();

	bool bankrupt();

	~User();

private:
	// Validates the bet input made by the User -- If not enough or bad input -> returns false.
	bool validateBet();

	// Validates the move input made by the User -- Must be 'Hit' || 'Fold'
	bool validateInput();
};

#endif // USER_H