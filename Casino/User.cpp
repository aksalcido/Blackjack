#include "User.h"

User::User(int funds) : Player(funds) {

}

User::User(const User& u) {

}

int User::getBetInput() {
	int bet;

	std::cin >> bet;
	
	return bet;
}

std::string User::getMoveInput() {
	std::string move;

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