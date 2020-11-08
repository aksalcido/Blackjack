#include "Dealer.h"


Dealer::Dealer(int funds) : Player(funds) {

}


Dealer::Dealer(const Dealer& b) : deck(b.deck) {

}

void Dealer::dealRemainingCards() {

}

void Dealer::resetAndShuffle() {
	deck.restart();
	deck.shuffle();
}

void Dealer::displayDeck() {
	deck.displayDeck();
}

Card* Dealer::dealCard() {
	return deck.top();
}

Dealer::~Dealer() {

}