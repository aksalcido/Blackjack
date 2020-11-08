#include "Player.h"

Player::Player() : funds(1000) {
	
}

Player::Player(int funds) : funds(funds) {

}

Player::Player(const Player& p) : funds(p.funds), hand(p.hand) {

}

void Player::addCardToHand(Card* card) {
	hand.addCardToHand(card);
}

void Player::clearHand() {
	hand.clear();
}

void Player::addFunds(int extra) {
	funds += extra;
}

void Player::decreaseFunds(int loss) {
	funds -= loss;
}

int Player::getFunds() const {
	return funds;
}

Hand Player::getHand() const {
	return hand;
}

Player::~Player() {

}