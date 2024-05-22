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

/// <summary>
/// This method shuffles the deck of cards using the Fisher-Yates algorithm.
/// The Fisher-Yates algorithm is an algorithm for generating a random permutation of a finite sequence.
/// The algorithm effectively puts all the elements into a hat, and then draws them out one at a time randomly.
/// The algorithm produces an unbiased permutation: every permutation is equally likely.
/// The modern version of the algorithm is efficient: it takes time proportional to the number of items being shuffled and shuffles them in place.
/// </summary>
void Deck::shuffle()
{
    std::random_device rd;
    std::mt19937 g(rd());
    std::shuffle(cards.begin(), cards.end(), g);
}

/// <summary>
/// This method draws a card from the deck.
/// </summary>
/// <returns>Card</returns>
/// <remarks>
/// This method removes the last card from the deck and returns it.
/// </remarks>
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