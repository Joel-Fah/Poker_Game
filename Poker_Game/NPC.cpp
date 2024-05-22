#include "NPC.h"

/// <summary>
/// This method shuffles the deck of cards.
/// </summary>
/// <param name="deck">The deck of cards to shuffle.</param>
void NPC::shuffleDeck(Deck& deck) {
    deck.shuffle();
}

/// <summary>
/// This method deals a card to a player.
/// </summary>
/// <param name="player">The player to deal the card to.</param>
void NPC::dealCard(Player& player, Deck& deck) {
    player.receiveCard(deck.drawCard());
}