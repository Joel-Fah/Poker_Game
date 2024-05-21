#pragma once
#include <vector>
#include <algorithm>
#include <random>

#include "Card.h"

// The Deck class will manage a collection of Card objects.
class Deck
{
private:
    std::vector<Card> cards;

public:
    Deck();
    virtual ~Deck();

    void shuffle();
    Card drawCard();
};
