#ifndef BLACKJACK_H
#define BLACKJACK_H

#pragma once
#include "User.h"
#include "Dealer.h"
#include "Display.h"

/* Prompt Messages */
const std::string INPUT_BET_MSG = "Please input your bet: ";
const std::string MOVE_INPUT_MSG = "Input Move: 'hit' || 'stand':  ";

const std::string USER_HIT = "hit";
const std::string USER_STAND = "stand";

const std::string USER_STR = "User";
const std::string DEALER_STR = "Dealer";
const std::string TIE_STR = "Tie";

const int ROYAL_CARD = 10;
const int ACE_CARD = 11;

const int START_CARDS = 2;
const int BET_MULTIPLIER = 2;

typedef std::pair<int, int> HandValue;

enum class Result { WIN, LOSS, TIE };

class Blackjack
{
public:
	// Blackjack constructor that takes a User and Dealer derived from Player. Both are the 2 players of the game.
	Blackjack(User* user, Dealer* dealer, Display* display);

	// Program executed through play(). Runs the entirity of the game of Blackjack in this function.
	void play();
	
	// Process user move whether the user wishes to 'hit' or 'stand' on their turn. If 'stand', roundOver is set to True.
	void gamemove(std::string input, bool& roundOver);

	// Determines if the User or dealer wins. Funds are awarded or removed from User/Dealer depending on winner.
	std::string determineWinner(const HandValue& userHand, int bet);

	// Destructor
	~Blackjack();

private:
	User* user;
	Dealer* dealer;
	Display* display;

private:
	int round;
	bool gameover;

	// Deals a card to the Player represented by playerStr and displays it the console. cardNumber represents the number of cards being dealt at once. By default it is 0, but in the case that:
	// We are beginning a new round, cardNumber is == START_CARDS (2) and we use the cardNumber to ensure that we DO NOT show the Dealer's second card.
	void dealAndDisplay(std::string playerStr, int cardNumber = 1);

	// Prompts the User for their 'bet', displays it and returns it to be used for the round
	int placeBet();

	// Prompts the User for their 'move', displays it and returns it to be used for the round
	std::string getMove();

	// Processes the round by checking if the user has broke, or if roundOver == true then checks who won between User and Dealer.
	void processRound(const HandValue& userHand, int bet, bool& roundOver);

	// After the User has chosen to stand, we deal the remaining cards to the Dealer
	void dealDealersCards();

	// Checks for Gameover by seeing if the User is bankrupt or not, if so then sets gameover == true.
	void checkForGameover();

	// Prepares for the next round by clearing the player's hands, reseting the deck, and incrementing the round number.
	void newRound();

	// Deals the 2 starting Cards to the User and Dealer at the beginning of each round
	void dealRoundCards();

	// Returns a HandValue that represents the total of the hand argument. HandValue represents a std::pair<int, int> where
	// the values represent the value of the hand, but the second value represents the special case if the User has an Ace card.
	HandValue getHandValue(const Hand& hand);
	
	// Returns a boolean True if the handValue passed exceeds the maximum of 21. False otherwise.
	bool playerBroke(const HandValue& handValue);

	// Compares handOne to handTwo. The result is in regards to handOne, where if its higher than handTwo -> returns a Win, otherwise a Loss or Tie.
	Result compare(const HandValue& handOne, const HandValue& handTwo);
};

#endif // BLACKJACK_H