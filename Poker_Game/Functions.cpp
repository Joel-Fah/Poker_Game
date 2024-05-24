#include "Functions.h"

/// <summary>
/// This function displays the main menu and gets the user's choice.
/// Then after every choice, it clears the screen.
/// </summary>
/// <returns></returns>
unsigned int mainMenu()
{
    int choice;
    // Display main menu options and get user choice enclosed in a box pattern made of + - | characters
    std::cout << "+----------------------------------------+" << "\n";
    std::cout << "| Poker Game - Main Menu                 |" << "\n";
    std::cout << "+----------------------------------------+" << "\n";
    std::cout << "| 1. Launch a new game                   |" << "\n";
    std::cout << "| 2. Exit                                |" << "\n";
    std::cout << "+----------------------------------------+" << "\n";
    std::cout << "Enter your choice >>> ";
    std::cin >> choice;

    // Clear screen
    system(CLEAR);

    return choice;
}

/// <summary>
/// Collects the card display strings for each card.
/// Iterates through each line of the card displays and prints them side by side.
/// </summary>
/// <param name="cards">The card layout.</param>
void displayCardsSideBySide(const std::vector<Card>& cards) {
    std::vector<std::vector<std::string>> cardDisplays;

    // Get card display strings for each card
    for (const auto& card : cards) {
        cardDisplays.push_back(card.drawCardLayout());
    }

    // Print each line of the card layout side by side
    for (int i = 0; i < cardDisplays[0].size(); ++i) {
        for (const auto& cardDisplay : cardDisplays) {
            fmt::print("{}  ", cardDisplay[i]);
        }
        fmt::print("\n");
    }
}