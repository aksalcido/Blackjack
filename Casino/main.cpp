#include <iostream>
#include "User.h"
#include "Dealer.h"
#include "Blackjack.h"

constexpr int BASE_FUNDS = 500;
constexpr int DEALER_FUNDS = 1000;


int main() {
	User* user = new User(BASE_FUNDS);
	Dealer* dealer = new Dealer(DEALER_FUNDS);
	Blackjack blackjack(user, dealer);
	
	blackjack.play();

	delete user;
	delete dealer;

	return 0;
}