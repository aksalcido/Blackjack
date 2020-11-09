#include "Deck.h"


Deck::Deck() : currentIndex(0) {
	newDeck();
	shuffle();
}

Deck::Deck(const Deck& d) : deck(d.deck) {
	shuffle();
}

Card* Deck::top() {
	return deck[currentIndex++];
}

void Deck::shuffle() {
	auto rng = std::default_random_engine{ };
	std::shuffle(std::begin(deck), std::end(deck), rng);
}

void Deck::restart() {
	currentIndex = 0;
}

void Deck::displayDeck() const {
	for (int i = currentIndex; i < DECK_SIZE; i++) {
		Card* card = deck[i];

		Suit s = card->getSuit();
		const char* suitString;

		if (s == Suit::Diamond)
			suitString = " of Diamond";
		else if (s == Suit::Club)
			suitString = " of Club";
		else if (s == Suit::Heart)
			suitString = " of Heart";
		else
			suitString = " of Spade";
		
		std::cout << card->getFaceValue() << suitString << std::endl;
	}
}

void Deck::newDeck() {
	std::vector<Suit> suits = { Suit::Diamond, Suit::Club, Suit::Heart, Suit::Spade };

	for (int cardValue = 1; cardValue <= 13; cardValue++) {
		for (int j = 0; j < suits.size(); j++) {
			Suit suit = suits[j];
			std::string cardName;
			
			if (cardValue == 1)
				cardName = "Ace";
			else if (cardValue == 11)
				cardName = "Jack";
			else if (cardValue == 12)
				cardName = "Queen";
			else if (cardValue == 13)
				cardName = "King";
			else
				cardName = std::to_string(cardValue);

			deck.push_back(new Card(suit, cardValue, cardName));
		}
	}
}

Deck::~Deck() {
	for (int i = 0; i < DECK_SIZE; i++) {
		delete deck[i];
	}
}