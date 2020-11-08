#include "Display.h"


Display::Display() : hConsole(GetStdHandle(STD_OUTPUT_HANDLE)) {
	
}

void Display::prompt(std::string msg) {
	SetConsoleTextAttribute(hConsole, 11);
	std::cout << msg;

	SetConsoleTextAttribute(hConsole, 15); // Sets Console Text Color back to White
}

void Display::displayRoundStart(int funds, int round) {
	std::cout << "-----------------------------------" << std::endl;

	std::cout << "Current Funds -- ";
	
	SetConsoleTextAttribute(hConsole, 2);
	std::cout << "$" << funds;

	SetConsoleTextAttribute(hConsole, 15);
	std::cout << " | Round -- ";

	SetConsoleTextAttribute(hConsole, 12);
	std::cout << round << std::endl;

	SetConsoleTextAttribute(hConsole, 15);
	std::cout << "-----------------------------------" << std::endl;

	SetConsoleTextAttribute(hConsole, 15); // Sets Console Text Color back to White
}

void Display::displayCard(Card* card) {
	std::cout << "The user just drew a ";
	int faceValue = card->getFaceValue();

	SetConsoleTextAttribute(hConsole, 7);
	if (faceValue == 1) {
		std::cout << "Ace of ";
	}
	else if (faceValue == 11) {
		std::cout << "Jack of ";
	}
	else if (faceValue == 12) {
		std::cout << "Queen of ";
	}
	else if (faceValue == 13) {
		std::cout << "King of ";
	}
	else {
		std::cout << card->getFaceValue() << " of ";
	}

	if (card->getSuit() == Suit::Diamond)
		std::cout << "Diamond";

	if (card->getSuit() == Suit::Club)
		std::cout << "Club";

	if (card->getSuit() == Suit::Heart)
		std::cout << "Heart";

	if (card->getSuit() == Suit::Spade)
		std::cout << "Spade";

	std::cout << "\n";
	SetConsoleTextAttribute(hConsole, 15); // Sets Console Text Color back to White
}

void Display::displayBroke() {
	std::cout << "The User Broke 21..." << std::endl;

	SetConsoleTextAttribute(hConsole, 15); // Sets Console Text Color back to White
}

void Display::displayWinner(std::string winner, int round) {
	std::cout << "The winner of Round ";
	
	SetConsoleTextAttribute(hConsole, 12);
	std::cout << round;

	SetConsoleTextAttribute(hConsole, 15);
	std::cout << " is the ";

	SetConsoleTextAttribute(hConsole, 14);
	std::cout << winner << std::endl;

	SetConsoleTextAttribute(hConsole, 15); // Sets Console Text Color back to White
}

void Display::displayGameover() {
	SetConsoleTextAttribute(hConsole, 4);
	std::cout << "GAMEOVER! THE USER HAS WENT BANKRUPT X_X" << std::endl;

	SetConsoleTextAttribute(hConsole, 15); // Sets Console Text Color back to White
}

void Display::displayHandToConsole(const HandValue& handValue, std::string playerStr) const {
	std::cout << "Current hand of the ";

	SetConsoleTextAttribute(hConsole, 14);
	std::cout << playerStr << ": ";
	
	SetConsoleTextAttribute(hConsole, 13);
	std::cout << handValue.first;

	if (handValue.first != handValue.second) {
		SetConsoleTextAttribute(hConsole, 15);
		std::cout << " OR ";
		SetConsoleTextAttribute(hConsole, 13);
		std::cout << handValue.second;
	}
	std::cout << "\n\n";

	SetConsoleTextAttribute(hConsole, 15); // Sets Console Text Color back to White
}

void Display::displayBetToConsole(int bet) const {
	std::cout << "  ---> Bet made from User: ";
	
	SetConsoleTextAttribute(hConsole, 2);
	std::cout << "$" << (bet / 2) << "\n" << std::endl;

	SetConsoleTextAttribute(hConsole, 15); // Sets Console Text Color back to White
}

void Display::displayMoveToConsole(std::string userMove) const {
	SetConsoleTextAttribute(hConsole, 15);
	std::cout << "  ---> User has chose to: ";

	SetConsoleTextAttribute(hConsole, 3);
	std::cout << userMove << "\n" << std::endl;

	SetConsoleTextAttribute(hConsole, 15); // Sets Console Text Color back to White
}


Display::~Display() {

}