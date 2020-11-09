#include "Display.h"


Display::Display() : hConsole(GetStdHandle(STD_OUTPUT_HANDLE)) {
	
}

void Display::prompt(std::string msg) {
	changeColor(Color::LIGHTCYAN);
	std::cout << msg;
	changeColor(Color::WHITE); // Sets Console Text Color back to White
}

void Display::displayRoundStart(int funds, int round) {
	std::cout << "-----------------------------------" << std::endl;
	std::cout << "Current Funds -- ";
	
	changeColor(Color::GREEN);
	std::cout << "$" << funds;

	changeColor(Color::WHITE);
	std::cout << " | Round -- ";

	changeColor(Color::LIGHTRED);
	std::cout << round << std::endl;

	changeColor(Color::WHITE);
	std::cout << "-----------------------------------" << std::endl;

	changeColor(Color::WHITE); // Sets Console Text Color back to White
}

void Display::displayCard(Card* card) {
	std::cout << "The user just drew a ";
	int faceValue = card->getFaceValue();

	changeColor(Color::LIGHTGRAY);	
	std::cout << card->getName() << " of ";

	if (card->getSuit() == Suit::Diamond)
		std::cout << "Diamond";

	else if (card->getSuit() == Suit::Club)
		std::cout << "Club";

	else if (card->getSuit() == Suit::Heart)
		std::cout << "Heart";

	else if (card->getSuit() == Suit::Spade)
		std::cout << "Spade";

	std::cout << "\n";
	changeColor(Color::WHITE); // Sets Console Text Color back to White
}

void Display::displayBroke() {
	std::cout << "The User Broke 21..." << std::endl;

	changeColor(Color::WHITE); // Sets Console Text Color back to White
}

void Display::displayWinner(std::string winner, int round) {
	changeColor(Color::LIGHTGREEN);
	std::cout << "-----------------------------------\n";

	changeColor(Color::WHITE);
	std::cout << "The WINNER of Round ";
	
	changeColor(Color::LIGHTRED);
	std::cout << round;

	changeColor(Color::WHITE); // Sets Console Text Color back to White
	std::cout << " is the ";

	changeColor(Color::YELLOW);
	std::cout << winner << std::endl;

	changeColor(Color::LIGHTGREEN);
	std::cout << "-----------------------------------\n\n";

	changeColor(Color::WHITE); // Sets Console Text Color back to White
}

void Display::displayGameover() {
	changeColor(Color::RED);
	std::cout << "GAMEOVER! THE USER HAS WENT BANKRUPT X_X" << std::endl;

	changeColor(Color::WHITE); // Sets Console Text Color back to White
}

void Display::displayHandToConsole(const HandValue& handValue, std::string playerStr) const {
	std::cout << "Current hand of the ";

	changeColor(Color::YELLOW);
	std::cout << playerStr << ": ";
	
	changeColor(Color::LIGHTMAGENTA);
	std::cout << handValue.first;

	if (handValue.first != handValue.second) {
		changeColor(Color::WHITE);
		std::cout << " OR ";
		changeColor(Color::LIGHTMAGENTA);
		std::cout << handValue.second;
	}
	std::cout << "\n\n";

	changeColor(Color::WHITE); // Sets Console Text Color back to White
}

void Display::displayBetToConsole(int bet) const {
	std::cout << "  ---> Bet made from User: ";
	
	changeColor(Color::GREEN);
	std::cout << "$" << (bet / 2) << "\n" << std::endl;

	changeColor(Color::WHITE); // Sets Console Text Color back to White
}

void Display::displayMoveToConsole(std::string userMove) const {
	std::cout << "  ---> User has chose to: ";

	changeColor(Color::CYAN);
	std::cout << userMove << "\n" << std::endl;

	changeColor(Color::WHITE); // Sets Console Text Color back to White
}

void Display::changeColor(Color color) const {
	SetConsoleTextAttribute(hConsole, static_cast<int>(color));
}

Display::~Display() {

}