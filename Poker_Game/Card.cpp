#include "Card.h"

Card::Card(unsigned int number, Suit suit)
{
    this->number = number;
    this->suit = suit;
}

// Getters definitions

unsigned int Card::getNumber() const { return number; }
Suit Card::getSuit() const { return suit; }

// Methods

/// <summary>
/// Returns the string representation of the card number
/// (e.g., "A" for Ace, "J" for Jack, "Q" for Queen, "K" for King
/// if not, converts the input number ranging from 1 to 10 to a string).
/// </summary>
/// <returns>string</returns>
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

/// <summary>
/// Returns the string representation of the card suit 
/// (e.g. "♥" for HEARTS, "♦" for DIAMONDS, "♣" for CLUBS and "♠" for SPADES).
/// Returns an empty string in case of no match.
/// </summary>
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

/// <summary>
// Constructs and returns a vector of strings representing the card layout.
/// </summary>
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