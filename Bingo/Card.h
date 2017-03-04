//
// Created by Hayden Nielsen on 2/24/17.
//

#ifndef BINGO_CARD_H
#define BINGO_CARD_H

#include <vector>

#include "Numbers.h"

class Card {
private:
    int m_cardNumber;
    int m_cardSize;
    Numbers& m_numbers;
    std::vector<std::vector<int>> m_rows;

    const int PADDING = 6;

public:
    Card(int cardSize, int cardNum, Numbers& numbers);

    void printCard(std::ostream& out);

private:
    void printBreak(std::ostream& out);
    void padAndPrint(std::ostream& out, const int num);
    void padVertical(std::ostream& out);
};


#endif //BINGO_CARD_H
