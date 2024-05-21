#include "Functions.h"

// FUnction to display the main menu
unsigned int mainMenu()
{
    int choice;
    // Display main menu options and get user choice enclosed in a box pattern made of + - | characters
    std::cout << "+-----------------------------+" << "\n";
    std::cout << "| Poker Game - Main Menu      |" << "\n";
    std::cout << "+-----------------------------+" << "\n";
    std::cout << "| 1. Launch a new game        |" << "\n";
    std::cout << "| 2. Exit                     |" << "\n";
    std::cout << "+-----------------------------+" << "\n";
    std::cout << "Enter your choice >>> ";
    std::cin >> choice;

    // Clear screen
    system(CLEAR);

    return choice;
}

// Function to display cards side by side
void displayCardsSideBySide(const std::vector<Card>& cards) {
    std::vector<std::vector<std::string>> cardDisplays;

    // Get card display strings for each card
    for (const auto& card : cards) {
        cardDisplays.push_back(card.drawCardLayout());
    }

    // Print each line of the card displays side by side
    for (int i = 0; i < cardDisplays[0].size(); ++i) {
        for (const auto& cardDisplay : cardDisplays) {
            fmt::print("{}  ", cardDisplay[i]);
        }
        fmt::print("\n");
    }
}