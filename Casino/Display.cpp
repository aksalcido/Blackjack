#include "Display.h"


Display::Display() : hConsole(GetStdHandle(STD_OUTPUT_HANDLE)) {
	
}

void Display::welcomeSreen() const {
	changeColor(Color::YELLOW); // Sets Console Text Color back to White
	std::cout << "=======================================================================================" << std::endl;
	std::cout << "| BBBBBB   LL       AAAAAAA  CCCCCCC  KK    KK        JJ  AAAAAAA  CCCCCCC  KK    KK  |" << std::endl;
	std::cout << "| BB   BB  LL       AA   AA  CC       KK  KK          JJ  AA   AA  CC       KK  KK    |" << std::endl;
	std::cout << "| BBBBBB   LL       AAAAAAA  CC       KKKK      JJ    JJ  AAAAAAA  CC       KKKK      |" << std::endl;
	std::cout << "| BB   BB  LL       AA   AA  CC       KK  KK    JJ    JJ  AA   AA  CC       KK  KK    |" << std::endl;
	std::cout << "| BBBBBB   LLLLLLL  AA   AA  CCCCCCC  KK    KK  JJJJJJJJ  AA   AA  CCCCCCC  KK    KK  |" << std::endl;
	std::cout << "=======================================================================================" << std::endl;

	changeColor(Color::WHITE); // Sets Console Text Color back to White
}

void Display::prompt(std::string msg) const {
	changeColor(Color::LIGHTCYAN);
	std::cout << msg;
	changeColor(Color::WHITE); // Sets Console Text Color back to White
}

void Display::newline(int lines) const {
	for (int i = 0; i < lines; i++) {
		std::cout << "\n";
	}
}

void Display::displayRoundStart(int funds, int round) const {
	std::cout << BOXED_LINE;
	std::cout << "Current Funds -- ";
	
	changeColor(Color::GREEN);
	std::cout << "$" << funds;

	changeColor(Color::WHITE);
	std::cout << " | Round -- ";

	changeColor(Color::LIGHTRED);
	std::cout << round << std::endl;

	changeColor(Color::WHITE);
	std::cout << BOXED_LINE;

	changeColor(Color::WHITE); // Sets Console Text Color back to White
}

void Display::displayCard(Card* card, std::string playerStr) const {
	std::cout << "The ";

	changeColor(Color::YELLOW);
	std::cout << playerStr;

	changeColor(Color::WHITE);
	std::cout << " just drew a ";


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
	
	newline();
	changeColor(Color::WHITE); // Sets Console Text Color back to White
}

void Display::displayBroke() const {
	changeColor(Color::RED);

	std::cout << "THE USER BROKE 21!" << std::endl;

	changeColor(Color::WHITE); // Sets Console Text Color back to White
}

void Display::displayWinner(std::string winner, int round) const {
	newline();

	changeColor(Color::LIGHTGREEN);
	std::cout << BOXED_LINE;

	changeColor(Color::LIGHTGREEN);
	std::cout << "The WINNER of Round ";

	changeColor(Color::LIGHTRED);
	std::cout << round;

	changeColor(Color::LIGHTGREEN);
	std::cout << " is the ";

	changeColor(Color::YELLOW);
	std::cout << winner << std::endl;

	changeColor(Color::LIGHTGREEN);
	std::cout << BOXED_LINE;

	newline(2);
	changeColor(Color::WHITE); // Sets Console Text Color back to White
}


void Display::displayGameover(bool bankrupt) const {
	changeColor(Color::RED);

	if (bankrupt)
		std::cout << GAMEOVER_MSG;
	
	changeColor(Color::WHITE); // Sets Console Text Color back to White

	std::cout << "Goodbye!" << std::endl;
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

	newline();
	changeColor(Color::WHITE); // Sets Console Text Color back to White
}

void Display::displayBetToConsole(int bet, int userFunds) const {
	std::cout << INPUT_ARROW << "Bet made from User: ";
	
	changeColor(Color::GREEN);

	if (bet >= userFunds)
		std::cout << "THE USER IS GOING ALL IN WITH: $" << userFunds;
	else
		std::cout << "$" << bet;

	newline(2);
	changeColor(Color::WHITE); // Sets Console Text Color back to White
}

void Display::displayMoveToConsole(std::string userMove) const {
	std::cout << INPUT_ARROW << "User has chose to: ";

	changeColor(Color::CYAN);
	std::cout << userMove << "\n" << std::endl;

	changeColor(Color::WHITE); // Sets Console Text Color back to White
}

void Display::changeColor(Color color) const {
	SetConsoleTextAttribute(hConsole, static_cast<int>(color));
}

void Display::checkForQuit(bool& gameover) const {
	// The User only has the option of continuing if it is not already gameover
	if (!gameover) {
		prompt("Type anything to continue the game OR 'q' to quit: ");

		std::string buffer;
		std::cin >> buffer;

		if (buffer == "q")
			gameover = true;
	}
}

Display::~Display() {

}