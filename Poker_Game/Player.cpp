#include "Player.h"

Player::Player() {}

// document this function

/// <summary>
/// This method receives a card and adds it to the player's hand.
/// </summary>
/// <param name="card">The card to add to the player's hand.</param>
void Player::receiveCard(const Card& card) {
    hand.addCard(card);
}

Hand& Player::getHand() {
    return hand;
}