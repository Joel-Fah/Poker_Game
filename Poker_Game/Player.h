#pragma once
#include "Hand.h"

class Player {
private:
    Hand hand;

public:
    Player();

    void receiveCard(const Card& card);
    Hand& getHand();
};
