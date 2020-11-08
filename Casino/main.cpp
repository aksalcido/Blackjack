#include <iostream>
#include "Blackjack.h"

constexpr int BASE_FUNDS = 500;
constexpr int DEALER_FUNDS = 1000;


int main() {
	User* user = new User(BASE_FUNDS);
	Dealer* dealer = new Dealer(DEALER_FUNDS);
	Display* display = new Display();

	Blackjack blackjack(user, dealer, display);
	blackjack.play();

	delete user;
	delete dealer;
	delete display;

	return 0;
}