//
// Created by Stephen Clyde on 2/16/17.
//

#ifndef BINGO_DECK_H
#define BINGO_DECK_H

#include <ostream>
#include <vector>

#include "Card.h"
#include "Numbers.h"

// TODO: Extend this definition as you see fit

class Deck {
private:
    std::vector<Card*> m_cards;
    Numbers m_numbers;

public:
    Deck(int cardSize, int cardCount, int numberMax);
    ~Deck();

    void print(std::ostream& out) const;
    void print(std::ostream& out, int cardIndex) const;
};

#endif //BINGO_DECK_H
