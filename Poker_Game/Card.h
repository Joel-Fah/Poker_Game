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

class Card
{
private:
    unsigned int number;
    Suit suit;

public:
    Card(unsigned int number, Suit suit);
    virtual ~Card();

    // Methods

    std::string getCardNumber() const;
    std::vector<std::string> drawCardLayout() const;
    std::string getCardTypeSymbol() const;

    // Getters declarations

    unsigned int getNumber() const;
    Suit getSuit() const;
};