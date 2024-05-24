#pragma once
#include <vector>
#include <map>

#include "Card.h"

// Hand rankings
enum class HandRanking {
    Straight_Flush,
    Three_Of_A_Kind,
    Straight,
    Flush,
    Pair,
    Mini_Royal,
    Nothing
};

class Hand {
private:
    std::vector<Card> cards;

    bool isFlush() const;
    bool isStraight() const;
    bool isThreeOfAKind() const;
    bool isPair() const;
    bool isMiniRoyal() const;

public:
    void addCard(const Card& card);
    const std::vector<Card>& getCards() const;

    HandRanking getHandRanking() const;
    static int getHandRankingValue(HandRanking ranking);
    static std::string handRankingToString(HandRanking ranking);
    static int compareHands(const Hand& playerHand, const Hand& dealerHand);
};