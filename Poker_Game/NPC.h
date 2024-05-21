#pragma once
#include "Player.h"
#include "Deck.h"

class NPC : public Player {
public:
    void shuffleDeck(Deck& deck);
    void dealCard(Player& player, Deck& deck);
};
