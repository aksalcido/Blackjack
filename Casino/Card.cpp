#include "Card.h"


Card::Card(Suit suit, int face) : suit(suit), face(face) {

}

Suit Card::getSuit() const {
	return suit;
}

int Card::getFaceValue() const {
	return face;
}

Card::~Card() {

}