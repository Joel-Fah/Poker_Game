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
    system(CLEAR);
    int menuChoice;

    do {
		menuChoice = mainMenu();

		switch(menuChoice) {
		case 1:
			{
				Game game(3);
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