#include "User.h"

User::User(int funds) : Player(funds) {

}

User::User(const User& u) {

}

int User::getBetInput() {
	int bet;
	std::cin >> bet;

	while (std::cin.fail()) {
		std::cerr << "Please Input an integer: " << std::endl;
		std::cin.clear();
		std::cin.ignore(256, '\n');
		std::cin >> bet;
	}

	return bet;
}

std::string User::getMoveInput() {
	std::string move;

	while (move != "hit" && move != "stand") {
		std::cin >> move;

		if (move != "hit" && move != "stand") {
			std::cerr << "Invalid Move Made..Try again" << std::endl;
		}
	}

	return move;
}

bool User::bankrupt() {
	return getFunds() <= 0;
}

User::~User() {

}