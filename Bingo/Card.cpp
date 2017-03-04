//
// Created by Hayden Nielsen on 2/24/17.
//

#include "Card.h"

#include <ostream>
#include <iomanip>

Card::Card(int cardSize, int cardNum, Numbers& numbers) :
    m_cardSize(cardSize),
    m_cardNumber(cardNum),
    m_numbers(numbers),
    m_rows()
{ m_numbers.getNumbers(m_rows); }

void Card::printCard(std::ostream& out) {
    out << "Card #" << m_cardNumber << std::endl;
    printBreak(out);
    for (std::vector<int> i : m_rows) {
        padVertical(out);
        for (int j : i) {
            padAndPrint(out, j);
        }
        out << "|" << std::endl;
        padVertical(out);
        printBreak(out);
    }
}

void Card::printBreak(std::ostream& out) {
    out << " ";
    for (unsigned int i = 0; i < m_cardSize * (PADDING + 4) - 1; ++i) out << "-";
    out << std::endl;
}

void Card::padAndPrint(std::ostream& out, const int num) {
    std::string pad (PADDING / 2, ' ');
    out << "|" << pad << std::setw(3) << num << pad;
}

void Card::padVertical(std::ostream& out) {
    const std::string verticalPad = std::string(1, '|') += std::string(PADDING + 3, ' ');

    for (unsigned int j = 0; j < m_cardSize; ++j) out << verticalPad;
    out << "|" <<std::endl;
}