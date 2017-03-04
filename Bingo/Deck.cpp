//
// Created by Stephen Clyde on 2/16/17.
//

#include "Deck.h"

Deck::Deck(int cardSize, int cardCount, int numberMax) :
    m_numbers(cardSize, numberMax),
    m_cards()
{
    for (unsigned int i = 1; i <= cardCount; ++i) {
        m_cards.push_back(new Card(cardSize, i, m_numbers));
    }
}

Deck::~Deck()
{
    for (Card* i : m_cards) delete i;
}

void Deck::print(std::ostream& out) const
{
    for (Card* i : m_cards) i->printCard(out);
}

void Deck::print(std::ostream& out, int cardIndex) const
{
    if (cardIndex > m_cards.size()) {
        out << "Index out of range.\n";
        return;
    }

    out << std::endl;
    m_cards.at(cardIndex - 1)->printCard(out);
    out << std::endl;
}



