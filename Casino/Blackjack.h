#ifndef BLACKJACK_H
#define BLACKJACK_H

#pragma once
#include "User.h"
#include "Dealer.h"

const std::string USER_HIT = "hit";
const std::string USER_FOLD = "fold";

const int ACE = 1;
const int JACK = 11;
const int QUEEN = 12;
const int KING = 13;

const int START_CARDS = 2;

typedef std::pair<int, int> HandValue;

class Blackjack
{
public:
	// Blackjack constructor that takes a User and Dealer derived from Player. Both are the 2 players of the game.
	Blackjack(User* user, Dealer* dealer);

	// Program executed through play(). Runs the entirity of the game of Blackjack in this function.
	void play();
	
	// Process user move whether the user wishes to 'hit' or 'fold' on their turn. If 'fold', roundOver is set to True.
	void gamemove(std::string input, bool& roundOver);

	// Determines if the User or dealer wins. Funds are awarded or removed from User/Dealer depending on winner.
	void determineWinner(const HandValue& userHand, int bet);

	void results();

	// Destructor
	~Blackjack();

private:
	User* user;
	Dealer* dealer;

private:
	int round;
	bool gameover;

	void processRound(const HandValue& userHand, int bet, bool& roundOver);

	void checkForGameover();

	void newRound();

	void dealRoundCards();

	HandValue getHandValue(const Hand& hand);

	bool userBroke(const HandValue& handValue);

	/* Console Display Methods */
	void displayHandToConsole(const HandValue& handValue) const;

	void displayBetToConsole(int bet) const;

	void displayMoveToConsole(std::string userMove) const;

};

#endif // BLACKJACK_H