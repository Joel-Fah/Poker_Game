#include "Player.h"

Player::Player() {}

void Player::receiveCard(const Card& card) {
    hand.addCard(card);
}

Hand& Player::getHand() {
    return hand;
}