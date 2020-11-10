#include "Blackjack.h"


Blackjack::Blackjack(User* user, Dealer* dealer, Display* display) : user(user), dealer(dealer), display(display), round(1), gameover(false) {

}

void Blackjack::play() {
	while (!gameover) {
		bool roundOver = false;
		int bet = placeBet();
		
		// Acquire First 2 Cards for both User && Dealer
		dealRoundCards();
		display->displayHandToConsole(getHandValue(user->getHand()), USER_STR);
	
		while (!roundOver) {
			std::string input = getMove();

			// Makes a move based on the user input for the current round
			gamemove(input, roundOver);

			// Acquires the value of the User's hand for the current round
			HandValue userHand = getHandValue(user->getHand());

			// Checks if user has broke or if there is a winner yet. Potentially sets roundOver = true if UserHand breaks 21.
			processRound(userHand, bet, roundOver);
		}

		checkForGameover();
	}

	// Displays Gameover differently depending on if the User went bankrupt OR decided to quit
	display->displayGameover(user->bankrupt());
}

void Blackjack::gamemove(std::string input, bool& roundOver) {
	if (input == USER_HIT) {
		Card* newCard = dealer->dealCard();
		user->addCardToHand(newCard);
		display->displayCard(newCard, USER_STR);
	}
	else if (input == USER_STAND) {
		dealDealersCards();
		display->displayHandToConsole(getHandValue(dealer->getHand()), DEALER_STR);
		roundOver = true;
	}
}

std::string Blackjack::determineWinner(const HandValue& userHand, int bet) {
	HandValue dealerHand = getHandValue(dealer->getHand());
	Result result = compare(userHand, dealerHand);
	std::string winner;

	// If User wins then we add the funds for the User and decrease from the Dealer
	if (result == Result::WIN) {
		user->addFunds(bet);
		dealer->decreaseFunds(bet);
		return USER_STR;
	}
	// If User loses then we decrease the funds for the User and add funds to the Dealer
	else if (result == Result::LOSS) {
		user->decreaseFunds(bet);
		dealer->addFunds(bet);
		return DEALER_STR;
	}
	// If Tie we simply return original bet back to both players
	else {
		user->addFunds(bet);
		dealer->addFunds(bet);
		return TIE_STR;
	}
}

void Blackjack::dealAndDisplay(std::string playerStr, int cardNumber) {
	Player* player;

	if (playerStr == USER_STR)
		player = user;
	else
		player = dealer;

	Card* newCard = dealer->dealCard();

	// The User never knows the second card that the Dealer drew, so instead we just show the User the value of the Dealer's one card
	if (playerStr == DEALER_STR && cardNumber == START_CARDS)
		display->displayHandToConsole(getHandValue(dealer->getHand()), playerStr);
	else
		display->displayCard(newCard, playerStr);

	player->addCardToHand(newCard);
}

int Blackjack::placeBet() {
	display->displayRoundStart(user->getFunds(), round);
	display->prompt(INPUT_BET_MSG);

	int bet = user->getBetInput();
	int userFunds = user->getFunds();

	if (bet >= userFunds)
		bet = userFunds;

	display->displayBetToConsole(bet, userFunds);

	return bet;
}

std::string Blackjack::getMove() {
	display->newline();
	display->prompt(MOVE_INPUT_MSG);
	std::string input = user->getMoveInput();
	display->displayMoveToConsole(input);

	return input;
}

Result Blackjack::compare(const HandValue& handOne, const HandValue& handTwo) {
	if (playerBroke(handTwo))
		return Result::WIN;
	
	// The second value is always >= to the first value, so we use it UNLESS it has broken the limit of 21.
	int handOneHigh = (handOne.second <= 21 ? handOne.second : handOne.first);
	int handTwoHigh = (handTwo.second <= 21 ? handTwo.second : handTwo.first);
	
	// Compares the highest value of both player's hands and returns the result in regards to handOne. (WIN = Win for handOne)
	return handOneHigh > handTwoHigh ? Result::WIN : (handOneHigh < handTwoHigh ? Result::LOSS : Result::TIE);
}


HandValue Blackjack::getHandValue(const Hand& hand) {
	HandValue result{ 0, 0 };
	std::vector<Card*> h = hand.getHand();

	for (int i = 0; i < h.size(); i++) {
		int value = h[i]->getFaceValue();

		// Jack, Queen, King are represented as 11, 12, 13 respectively. Yet their ingame value is 10, so we must add values equivalent to in game value.
		if (value > ROYAL_CARD) {
			result.first += ROYAL_CARD;
			result.second += ROYAL_CARD;
		}
		// Ace can be worth 1 or 11, depending on the user's choice which is why we use two numbers in a pair to represent what the user's options are.
		else if (value == 1) {
			result.first += value;
			result.second += ACE_CARD;
		}
		// Most cases will go towards here and we will contain a pair of two of the same values.
		else {
			result.first += value;
			result.second += value;
		}
	}

	return result;
}

bool Blackjack::playerBroke(const HandValue& handValue) {
	return handValue.first > 21 && handValue.second > 21;
}


void Blackjack::processRound(const HandValue& userHand, int bet, bool& roundOver) {
	display->displayHandToConsole(userHand, USER_STR);
	std::string winner;

	// If User breaks -- Immediately Subtract Funds and round is over
	if (playerBroke(userHand)) {
		roundOver = true;
		user->decreaseFunds(bet);
		display->displayBroke();
		winner = DEALER_STR;
	}
	// This Flag is triggered only when gamemove sets roundOver to be true --> strictly based off user standing
	else if (roundOver) {
		winner = determineWinner(userHand, bet);
	}

	if (winner == USER_STR || winner == DEALER_STR || winner == TIE_STR)
		display->displayWinner(winner, round);
}

void Blackjack::dealDealersCards() {
	HandValue dealerHand = getHandValue(dealer->getHand());
	HandValue userHand;

	// While the dealer has not broke && dealer's hand is less than the players hand, we will continue dealing cards
	while (!playerBroke(dealerHand)) {
		HandValue userHand = getHandValue(user->getHand());
		Result res = compare(dealerHand, userHand);

		// If Dealer's hand results in a WIN compared to the User's hand, then the dealer does not need anymore cards
		if (res == Result::WIN || res == Result::TIE)
			return;

		// Otherwise the Dealer takes a risk of drawing another card in order to beat the User --> can result in the dealer going over 21 which is the condition for our While loop
		dealer->addCardToHand(dealer->dealCard());

		dealerHand = getHandValue(dealer->getHand());
	}
}

void Blackjack::checkForGameover() {
	if (user->bankrupt())
		gameover = true;

	display->checkForQuit(gameover);
	
	// Gameover can be triggered from the the User being bankrupt OR User forcefully quitting
	if (!gameover)
		newRound();
}

void Blackjack::newRound() {
	user->clearHand();
	dealer->clearHand();
	dealer->resetAndShuffle();
	round++;
}

void Blackjack::dealRoundCards() {
	for (int roundStartCard = 1; roundStartCard <= START_CARDS; roundStartCard++) {
		dealAndDisplay(USER_STR, roundStartCard);
		dealAndDisplay(DEALER_STR, roundStartCard);
	}

}

Blackjack::~Blackjack() {
	
}