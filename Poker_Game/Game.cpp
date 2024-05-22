#include "Game.h"

Game::Game(int numPlayers) {
    for (int i = 0; i < numPlayers; ++i) {
        players.emplace_back(Player());
    }
}

/// <summary>
/// This method starts the game by shuffling the deck, dealing cards to the players, and dealing cards to the computer.
/// </summary>
void Game::startGame() {
    int numberOfCardsDeal = 3;
    computer.shuffleDeck(deck);

    for (auto& player : players) {
        for (int j = 0; j < numberOfCardsDeal; ++j) {
            computer.dealCard(player, deck);
        }
    }

    // Also deal cards to the computer itself
    for (int j = 0; j < numberOfCardsDeal; ++j) {
        computer.receiveCard(deck.drawCard());
    }
}

/// <summary>
/// This method displays the cards of each player and the computer.
/// </summary>
void Game::displayPlayersCards() {
    for (size_t i = 0; i < players.size(); ++i) {
        std::cout << "Player " << i + 1 << "'s hand:\n";
        displayHand(players[i].getHand());
    }

    // Display the computer's (NPC) hand
    std::cout << "NPC's hand:\n";
    displayHand(computer.getHand());
}

/// <summary>
/// This method displays the cards of a hand side by side.
/// </summary>
/// <param name="cards">The cards to display.</param>
void Game::displayHand(const Hand& hand) {
    const auto& cards = hand.getCards();

	// Display cards side by side
	displayCardsSideBySide(cards);

    // Display Hand ranking
    HandRanking ranking = hand.getHandRanking();
    std::cout << "Hand Ranking: " << Hand::handRankingToString(ranking) << "\n";
    std::cout << "Points: " << Hand::getHandRankingValue(ranking) << "\n";

	std::cout << "\n";
	std::cout << "+----------------------------------------+";
	std::cout << "\n\n";
}

void Game::determineWinners() {
    std::cout << "\n+----------------------------------------+\n";
    std::cout << "| Game Results:                          |\n";
    std::cout << "+----------------------------------------+\n";

    for (size_t i = 0; i < players.size(); ++i) {
        int result = Hand::compareHands(players[i].getHand(), computer.getHand());
        if (result == 1) {
            std::cout << "| - Player " << i + 1 << " wins against the dealer!\t |\n";
        }
        else if (result == -1) {
            std::cout << "| - Dealer wins against Player " << i + 1 << ".\t |\n";
        }
        else {
            std::cout << "| - Player " << i + 1 << " ties with the dealer.\t |\n";
        }
    }

    std::cout << "+----------------------------------------+";
    std::cout << "\n\n";
}