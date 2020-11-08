#include "Blackjack.h"


Blackjack::Blackjack(User* user, Dealer* dealer, Display* display) : user(user), dealer(dealer), display(display), round(1), gameover(false) {

}

void Blackjack::play() {
	//dealer->displayDeck(); // debug

	while (!gameover) {
		bool roundOver = false; // New Round Beginning

		display->displayRoundStart(user->getFunds(), round);
		display->prompt("Please input your bet: ");
		int bet = user->getBetInput() * BET_MULTIPLIER; // Acquire Bets from Player
		display->displayBetToConsole(bet);

		dealRoundCards(); // Acquire First 2 Cards for both User && Dealer
		display->displayHandToConsole(getHandValue(user->getHand()), "User");
	
		while (!roundOver) {
			// Get Input from User -- 'Hit' || 'Fold'
			display->prompt("Input Move: 'hit' or 'h' || 'fold' or 'f':  ");
			std::string input = user->getMoveInput();
			display->displayMoveToConsole(input);

			// Makes a move based on the user input for the current round
			gamemove(input, roundOver);
			
			// Acquires the value of the User's hand for the current round
			HandValue userHand = getHandValue(user->getHand());
			display->displayHandToConsole(userHand, "User");
			
			// Checks if user has broke or if there is a winner yet. Potentially sets roundOver = true if UserHand breaks 21.
			processRound(userHand, bet, roundOver);
		}

		// Checks for end of game -- Will set gameover = true if this is the case.
		checkForGameover();
	}

	display->displayGameover();
}

void Blackjack::gamemove(std::string input, bool& roundOver) {
	if (input == USER_HIT) {
		Card* newCard = dealer->dealCard();	// if hit to user
		user->addCardToHand(newCard);		// add card to user hand
		display->displayCard(newCard);
	}
	else if (input == USER_FOLD) {
		dealer->dealRemainingCards();       // get remaining cards for dealer
		display->displayHandToConsole(getHandValue(dealer->getHand()), "Dealer");
		roundOver = true;
	}
}

void Blackjack::determineWinner(const HandValue& userHand, int bet) {
	HandValue dealerHand = getHandValue(dealer->getHand());
	
	// compare player vs dealer
	Result result = compare(userHand, dealerHand);
	std::string winner;

	// If User wins then we add the funds for the User and decrease from the Dealer
	if (result == Result::WIN) {
		user->addFunds(bet);
		dealer->decreaseFunds(bet);
		winner = "User";
	}
	// If User loses then we decrease the funds for the User and add funds to the Dealer
	else if (result == Result::LOSS) {
		user->decreaseFunds(bet);
		dealer->addFunds(bet);
		winner = "Dealer";
	}
	// If Tie we simply return original bet back to both players
	else {
		user->addFunds(bet);
		dealer->addFunds(bet);
		winner = "Tie";
	}

	display->displayWinner(winner, round);
}

Result Blackjack::compare(const HandValue& userHand, const HandValue& dealerHand) {
	// Returns a Win right away if the User did not break and the Dealer did
	if (playerBroke(dealerHand))
		return Result::WIN;
	
	// The second value is always >= to the first value, so we use it UNLESS it has broken the limit of 21.
	int userHigh = (userHand.second <= 21 ? userHand.second : userHand.first);
	int dealerHigh = (dealerHand.second <= 21 ? dealerHand.second : dealerHand.first);
	
	// Simply compares the highest value of both player's hands and returns the result
	return userHigh > dealerHigh ? Result::WIN : (userHigh < dealerHigh ? Result::LOSS : Result::TIE);
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
	// If User breaks -- Immediately Subtract Funds and round is over
	if (playerBroke(userHand)) {
		roundOver = true;
		user->decreaseFunds(bet);
		display->displayBroke();
		display->displayWinner("Dealer", round);
	}
	// This Flag is triggered only when gamemove sets roundOver to be true --> strictly based off user folding
	else if (roundOver) {
		determineWinner(userHand, bet);
	}
}

void Blackjack::checkForGameover() {
	// check for gameover (e.g player == bankrupt)
	if (user->bankrupt())
		gameover = true;
	else
		newRound();	// if not gameover -- new round and reset deck
}

void Blackjack::newRound() {
	user->clearHand();
	dealer->clearHand();
	dealer->resetAndShuffle();
	round++;
}

void Blackjack::dealRoundCards() {
	for (int roundStartCards = 0; roundStartCards < START_CARDS; roundStartCards++) {
		Card* newCard = dealer->dealCard();
		user->addCardToHand(newCard);
		display->displayCard(newCard);
		dealer->addCardToHand(dealer->dealCard());
	}
}

Blackjack::~Blackjack() {
	
}