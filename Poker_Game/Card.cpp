#include "Card.h"

Card::Card(unsigned int number, Suit suit)
{
    this->number = number;
    this->suit = suit;
}

// Getters and Setters
unsigned int Card::getNumber() const { return number; }
Suit Card::getSuit() const { return suit; }

// Methods

// Get card number
std::string Card::getCardNumber() const
{
    switch (number)
    {
    case 1:
        return "A";
    case 11:
        return "J";
    case 12:
        return "Q";
    case 13:
        return "K";
    default:
        return std::to_string(number);
    }
}

// Get card suit symbol
std::string Card::getCardTypeSymbol() const
{
	switch (suit)
	{
    case Suit::HEARTS:
		return "♥";
	case Suit::DIAMONDS:
		return "♦";
	case Suit::CLUBS:
		return "♣";
	case Suit::SPADES:
		return "♠";
	default:
		return "";
	}
}

// Method to draw card layout and store in vector
std::vector<std::string> Card::drawCardLayout() const
{
    std::vector<std::string> card;
    std::string cardNumber = getCardNumber();
    card.push_back(fmt::format("┌─────────┐"));
    card.push_back(fmt::format("│ {:<2}      │", cardNumber));
    card.push_back(fmt::format("│         │"));
    card.push_back(fmt::format("│    {:<1}    │", getCardTypeSymbol()));
    card.push_back(fmt::format("│         │"));
    card.push_back(fmt::format("│      {:>2} │", cardNumber));
    card.push_back(fmt::format("└─────────┘"));

    return card;
}

// Destructor for Card class
Card::~Card()
{
}