#ifndef DISPLAY_H
#define DISPLAY_H
#pragma once
#include <iostream>
#include <Windows.h>
#include "Card.h"

typedef std::pair<int, int> HandValue;

enum class Color {
	BLUE = 1,
	GREEN = 2,
	CYAN = 3,
	RED = 4,
	MAGENTA = 5,
	BROWN = 6,
	LIGHTGRAY = 7,
	DARKGRAY = 8,
	LIGHTBLUE = 9,
	LIGHTGREEN = 10,
	LIGHTCYAN = 11,
	LIGHTRED = 12,
	LIGHTMAGENTA = 13,
	YELLOW = 14,
	WHITE = 15
};

const std::string BOXED_LINE = "-----------------------------------\n";

class Display
{
public:
	// Initializes a Display object that handles all of the console printing. This object prevents multiple std::cout statements
	// on the Blackjack.cpp file. As well as importing <Windows.h> to handle the color of the console printing using the HANDLE hConsole.
	Display();

	// Displays to the User a prompted msg argument
	void prompt(std::string msg);

	// Displays a newline to the console
	void newline(int lines = 1) const;

	// Displays the total 'funds' of the User and the current 'round'
	void displayRoundStart(int funds, int round);

	// Displays the contents of the card as it is drawn
	void displayCard(Card* card, std::string playerStr);

	// Displays when the User broke 21
	void displayBroke();

	// Displays the winner argument to the console for the current 'round' argument
	void displayWinner(std::string winner, int round);

	// Displays a simple GAMEOVER message
	void displayGameover(bool bankrupt);

	/* ===== Console Display Methods ===== */
	// Displays the hand value to the console which can be either from User or Dealer and that is represented by 'playerStr'
	void displayHandToConsole(const HandValue& handValue, std::string playerStr) const;

	// Displays the bet made by the user: 'bet' to the console
	void displayBetToConsole(int bet, int userFunds) const;

	// Displays the move made by the user: 'userMove' to the console
	void displayMoveToConsole(std::string userMove) const;

	void checkForQuit(bool& gameover);

	~Display();

private:
	HANDLE hConsole;

	void changeColor(Color color) const;
};

#endif // DISPLAY_H