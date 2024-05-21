#include "NPC.h"

void NPC::shuffleDeck(Deck& deck) {
    deck.shuffle();
}

void NPC::dealCard(Player& player, Deck& deck) {
    player.receiveCard(deck.drawCard());
}