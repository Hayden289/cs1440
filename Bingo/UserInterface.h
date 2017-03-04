//
// Created by Stephen Clyde on 2/16/17.
//

#ifndef BINGO_USER_INTERFACE_H
#define BINGO_USER_INTERFACE_H

#include <string>

class Deck;

class UserInterface {
private:
    Deck*   currentDeck = nullptr;

public:
    void run();

private:
    void createDeck();
    void deckMenu();
    void printCard();
    void saveDeck();

    std::string getStringInput(std::string prompt);
    int getNumberInput(std::string prompt, int rangeMin, int rangeMax);
};


#endif //BINGO_USER_INTERFACE_H
