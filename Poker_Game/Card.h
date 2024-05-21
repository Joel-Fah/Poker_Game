#pragma once
#define FMT_HEADER_ONLY
#include <fmt/core.h>

#include <iostream>
#include <string>
#include <vector>

enum class Suit {
	HEARTS = 1,
	DIAMONDS,
	CLUBS,
	SPADES,
};

//  Define a class Card with the attributes number and type and the method display
class Card
{
private:
    unsigned int number;
    Suit suit;

public:
    Card(unsigned int number, Suit suit);
    virtual ~Card();
    std::string getCardNumber() const;
    std::vector<std::string> drawCardLayout() const;
    std::string getCardTypeSymbol() const;

    // Getter and setters declaration
    unsigned int getNumber() const;
    Suit getSuit() const;
};