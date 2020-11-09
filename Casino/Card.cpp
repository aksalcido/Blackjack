#include "Card.h"


Card::Card(Suit suit, int face, std::string name) : suit(suit), face(face), name(name) {

}

Suit Card::getSuit() const {
	return suit;
}

int Card::getFaceValue() const {
	return face;
}

std::string Card::getName() const {
	return name;
}

Card::~Card() {

}