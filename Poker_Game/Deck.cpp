#include "Deck.h"

// Constructor to initialize the deck
Deck::Deck()
{
    for (int rank = 1; rank <= 13; ++rank)
    {
        cards.emplace_back(Card(rank, Suit::HEARTS));
        cards.emplace_back(Card(rank, Suit::DIAMONDS));
        cards.emplace_back(Card(rank, Suit::CLUBS));
        cards.emplace_back(Card(rank, Suit::SPADES));
    }
}

void Deck::shuffle()
{
    std::random_device rd;
    std::mt19937 g(rd());
    std::shuffle(cards.begin(), cards.end(), g);
}

Card Deck::drawCard()
{
    Card card = cards.back();
    cards.pop_back();
    return card;
}

// Destructor to delete the deck
Deck::~Deck()
{
}