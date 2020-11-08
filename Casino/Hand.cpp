#include "Hand.h"

Hand::Hand(int maxCards) {

}

void Hand::clear() {
	hand.clear();
}

void Hand::addCardToHand(Card* card) {
	hand.push_back(card);
}

std::vector<Card*> Hand::getHand() const {
	return hand;
}

Hand::~Hand() {

}