#pragma once
#include <vector>

#include "Player.h"
#include "NPC.h"
#include "Deck.h"
#include "Functions.h"

class Game {
private:
    NPC computer;
    std::vector<Player> players;
    Deck deck;

public:
    Game(int numPlayers);
	virtual ~Game() {}

    void startGame();
    void displayPlayersCards();
    void displayHand(const Hand& hand);
    void determineWinners();
};
