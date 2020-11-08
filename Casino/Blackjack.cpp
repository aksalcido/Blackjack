#include "Blackjack.h"


Blackjack::Blackjack(User* user, Dealer* dealer) : user(user), dealer(dealer), round(0), gameover(false) {

}

void Blackjack::play() {
	while (!gameover) {
		int bet = user->getBetInput(); 	// Acquire Bets from Player
		bool roundOver = false;				    // New Round Beginning
		dealRoundCards();                       // Acquire First 2 Cards for both User && Dealer

		displayBetToConsole(bet);
		displayHandToConsole(getHandValue(user->getHand()));
	
		while (!roundOver) {
			// Get Input from User -- 'Hit' || 'Fold'
			std::string input = user->getMoveInput();
			displayMoveToConsole(input);

			// Makes a move based on the user input for the current round
			gamemove(input, roundOver);
			
			// Acquires the value of the User's hand for the current round
			HandValue userHand = getHandValue(user->getHand());
			displayHandToConsole(userHand);
			
			// Checks if user has broke or if there is a winner yet. Potentially sets roundOver = true if UserHand breaks 21.
			processRound(userHand, bet, roundOver);
		}

		// Checks for end of game -- Will set gameover = true if this is the case.
		checkForGameover();
	}
}

void Blackjack::gamemove(std::string input, bool& roundOver) {
	if (input == USER_HIT) {
		Card* newCard = dealer->dealCard();	// if hit to user
		user->addCardToHand(newCard);		// add card to user hand
	}
	else if (input == USER_FOLD) {
		dealer->dealRemainingCards();       // get remaining cards for dealer
		roundOver = true;
	}
}

void Blackjack::determineWinner(const HandValue& userHand, int bet) {
	HandValue dealerHand = getHandValue(dealer->getHand());


	// compare player vs dealer
	bool userWins = false;

	if (userWins) {
		user->addFunds(bet);
		dealer->decreaseFunds(bet);
	}
	else {
		user->decreaseFunds(bet);
		dealer->addFunds(bet);
	}
}

HandValue Blackjack::getHandValue(const Hand& hand) {
	HandValue result{ 0, 0 };
	std::vector<Card*> h = hand.getHand();
	int value;

	for (int i = 0; i < h.size(); i++) {
		value = h[i]->getFaceValue();

		std::cout << "Value: " << value << std::endl; // debug

		// Jack, Queen, King are represented as 11, 12, 13 respected. Yet their ingame value is 10, so we must add values equivalent to in game value.
		if (value > 10) {
			result.first += 10;
			result.second += 10;
		}
		// Ace can be worth 1 or 11, depending on the user's choice which is why we use two numbers in a pair to represent what the user's options are.
		else if (value == 1) {
			result.first += value;
			result.second += 11;
		}
		// Most cases will go towards here and we will contain a pair of two of the same values.
		else {
			result.first += value;
			result.second += value;
		}
	}

	return result;
}

bool Blackjack::userBroke(const HandValue& handValue) {
	return handValue.first > 21 && handValue.second > 21;
}


void Blackjack::processRound(const HandValue& userHand, int bet, bool& roundOver) {
	// If User breaks -- Immediately Subtract Funds and round is over
	if (userBroke(userHand)) {
		user->decreaseFunds(bet);
		roundOver = true;
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
		user->addCardToHand(dealer->dealCard());
		dealer->addCardToHand(dealer->dealCard());
	}


}

void Blackjack::displayHandToConsole(const HandValue& handValue) const {
	std::cout << "User's current hand: " << handValue.first;
	if (handValue.first != handValue.second) {
		std::cout << " / " << handValue.second;
	}
	std::cout << "\n";
}

void Blackjack::displayBetToConsole(int bet) const {
	std::cout << "Bet made from User: " << bet << std::endl;
}

void Blackjack::displayMoveToConsole(std::string userMove) const {
	std::cout << "User has chose to: " << userMove << std::endl;
}

Blackjack::~Blackjack() {
	
}