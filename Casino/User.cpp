#include "User.h"

User::User(int funds) : Player(funds) {

}

User::User(const User& u) {

}

int User::getBetInput() {
	int bet;
	
	std::cout << "Current Funds -- $" << funds << std::endl;
	
	std::cout << "Please input your bet: ";
	std::cin >> bet;
	
	return bet;
}

std::string User::getMoveInput() {
	std::string move;

	std::cout << "Input Move: Hit || Fold: " << std::endl;
	std::cin >> move;

	while (move != "hit" && move != "h" && move != "fold" && move != "f") {
		std::cin >> move;

		if (move != "hit" && move != "h" && move != "fold" && move != "f") {
			std::cout << "Invalid Move Made..Try again" << std::endl;
		}
	}

	return move;
}

bool User::bankrupt() {
	return getFunds() <= 0;
}

bool User::validateBet() {
	return true;
}

bool User::validateInput() {
	return true;
}

User::~User() {

}