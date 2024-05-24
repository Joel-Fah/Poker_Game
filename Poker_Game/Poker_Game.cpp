// Poker_Game.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
// Clear screen command based on OS
#ifdef _WIN32
#define CLEAR "cls"
#else
#define CLEAR "clear"
#endif

#include "Functions.h"
#include "Game.h"

int main()
{
	
	/*// SECTION A: Test Card
	unsigned int number, suit;
	std::vector<Card> cards;

	// Get user input
	do {
		std::cout << "Enter the card number >>> ";
		std::cin >> number;

		if (number > 13 || number < 1) {
			std::cout << "Invalid card number\n\n";
		}
	} while (number > 13 || number < 1);

	do {
		std::cout << "\nSelect card suit (1 - 4): \n";
		std::cout << "   1. HEARTS\n";
		std::cout << "   2. DIAMONDS\n";
		std::cout << "   3. CLUBS\n";
		std::cout << "   4. SPADES\n";
		std::cout << "Choice >>> ";
		std::cin >> suit;

		if (suit > 4 || suit < 1) {
			std::cout << "Invalid suit entry.\n";
		}
	} while (suit > 4 || suit < 1);

	// display card
	cards.push_back(Card(number, static_cast<Suit>(suit)));
	displayCardsSideBySide(cards);
	

	// SECTION B: Share cards and Display
	
	unsigned int numPlayers;

	// Enter the number of players
	do {
		std::cout << "Enter the number of players between 1 and 3 >>> ";
		std::cin >> numPlayers;

		if (numPlayers < 1 || numPlayers > 3) {
			std::cout << "Invlaid entry.\n\n";
		}
	} while (numPlayers < 1 || numPlayers > 3);

	std::cout << "\n";

	Game game(numPlayers);
	game.startGame();
	game.displayPlayersCards();
	*/

    system(CLEAR);
    int menuChoice;
	unsigned int numPlayers;

	// Enter the number of players
	do {
		std::cout << "Enter the number of players between 1 and 3 >>> ";
		std::cin >> numPlayers;

		if (numPlayers < 1 || numPlayers > 3) {
			std::cout << "Invlaid entry.\n\n";
		}
	} while (numPlayers < 1 || numPlayers > 3);

	std::cout << "\n";

    do {
		menuChoice = mainMenu();

		switch(menuChoice) {
		case 1:
			{
				Game game(numPlayers);
				game.startGame();
				game.displayPlayersCards();
				game.determineWinners();
			}
			break;
		case 2:
			std::cout << "Exiting the game..." << "\n";
			break;
		default:
			std::cout << "Invalid choice. Please try again." << "\n";
			break;
		}
	} while (menuChoice != 2);

    return 0;
}