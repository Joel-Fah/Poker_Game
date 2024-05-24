#include "Hand.h"

/// <summary>
/// This method adds a card to the hand.
/// </summary>
/// <param name="card">The card to add to the hand.</param>
void Hand::addCard(const Card& card) {
	cards.push_back(card);
}

const std::vector<Card>& Hand::getCards() const {
    return cards;
}

/// <summary>
/// This method checks if the hand is a flush.
/// </summary>
/// <returns>True if the hand is a flush, false otherwise.</returns>
bool Hand::isFlush() const {
    return cards[0].getSuit() == cards[1].getSuit() && cards[1].getSuit() == cards[2].getSuit();
}

/// <summary>
/// This method checks if the hand is a straight.
/// </summary>
/// <returns>True if the hand is a straight, false otherwise.</returns>
bool Hand::isStraight() const {
    std::vector<unsigned int> numbers = { cards[0].getNumber(), cards[1].getNumber(), cards[2].getNumber() };
    std::sort(numbers.begin(), numbers.end());
    return (numbers[2] - numbers[1] == 1 && numbers[1] - numbers[0] == 1) ||
        (numbers[0] == 1 && numbers[1] == 12 && numbers[2] == 13); // Handling A, K, Q
}

/// <summary>
/// This method checks if the hand is a Three of a kind.
/// </summary>
/// <returns>True if the hand is a Three of a kind, false otherwise.</returns>
bool Hand::isThreeOfAKind() const {
    return cards[0].getNumber() == cards[1].getNumber() && cards[1].getNumber() == cards[2].getNumber();
}

/// <summary>
/// This method checks if the hand is a pair.
/// </summary>
/// <returns>True if the hand is a pair, false otherwise.</returns>
bool Hand::isPair() const {
    std::map<int, int> countMap;
    for (const auto& card : cards) {
        countMap[card.getNumber()]++;
    }
    return countMap.size() == 2; // One pair and one single card
}

/// <summary>
/// This method checks if the hand is a mini royal.
/// </summary>
/// <returns>True if the hand is a mini royal, false otherwise.</returns>
bool Hand::isMiniRoyal() const {
    std::vector<unsigned int> numbers = { cards[0].getNumber(), cards[1].getNumber(), cards[2].getNumber() };
    std::sort(numbers.begin(), numbers.end());
    return isFlush() && numbers[0] == 1 && numbers[1] == 12 && numbers[2] == 13;
}

HandRanking Hand::getHandRanking() const {
    if (isMiniRoyal()) return HandRanking::Mini_Royal;
    if (isThreeOfAKind()) return HandRanking::Three_Of_A_Kind;
    if (isStraight() && isFlush()) return HandRanking::Straight_Flush;
    if (isStraight()) return HandRanking::Straight;
    if (isFlush()) return HandRanking::Flush;
    if (isPair()) return HandRanking::Pair;
    return HandRanking::Nothing;
}

int Hand::getHandRankingValue(HandRanking ranking) {
    switch (ranking) {
    case HandRanking::Mini_Royal: return 6;
    case HandRanking::Straight_Flush: return 5;
    case HandRanking::Three_Of_A_Kind: return 4;
    case HandRanking::Straight: return 3;
    case HandRanking::Flush: return 2;
    case HandRanking::Pair: return 1;
    case HandRanking::Nothing: return 0;
    }
    return -1;
}

std::string Hand::handRankingToString(HandRanking ranking) {
    switch (ranking) {
    case HandRanking::Mini_Royal: return "Mini Royal";
    case HandRanking::Straight_Flush: return "Straight Flush";
    case HandRanking::Three_Of_A_Kind: return "Three Of A Kind";
    case HandRanking::Straight: return "Straight";
    case HandRanking::Flush: return "Flush";
    case HandRanking::Pair: return "Pair";
    case HandRanking::Nothing: return "Nothing";
    }
    return "Unknown";
}

// document this function

/// <summary>
/// This method compares two hands and determines the winner.
/// </summary>
/// <param name="playerHand">The player's hand.</param>
/// <param name="dealerHand">The dealer's hand.</param>
/// <returns>1 if the player wins, -1 if the dealer wins, 0 if it's a tie.</returns>
int Hand::compareHands(const Hand& playerHand, const Hand& dealerHand) {
    int playerRanking = getHandRankingValue(playerHand.getHandRanking());
    int dealerRanking = getHandRankingValue(dealerHand.getHandRanking());
    if (playerRanking > dealerRanking) return 1;  // Player wins
    if (playerRanking < dealerRanking) return -1; // Dealer wins
    // If rankings are the same, compare highest cards
    std::vector<int> playerCards, dealerCards;
    for (const auto& card : playerHand.getCards()) {
        playerCards.push_back(card.getNumber());
    }
    for (const auto& card : dealerHand.getCards()) {
        dealerCards.push_back(card.getNumber());
    }
    std::sort(playerCards.begin(), playerCards.end(), std::greater<int>());
    std::sort(dealerCards.begin(), dealerCards.end(), std::greater<int>());
    for (size_t i = 0; i < playerCards.size(); ++i) {
        if (playerCards[i] > dealerCards[i]) return 1;  // Player wins
        if (playerCards[i] < dealerCards[i]) return -1; // Dealer wins
    }
    return 0; // Tie
}