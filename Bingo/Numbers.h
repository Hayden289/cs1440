//
// Created by Hayden Nielsen on 2/24/17.
//

#ifndef BINGO_NUMBERS_H
#define BINGO_NUMBERS_H

#include <vector>

class Numbers {
private:
    int m_max;
    int m_size;

public:
    Numbers(int n, int m);

    void getNumbers(std::vector<std::vector<int>>& rows);
};


#endif //BINGO_NUMBERS_H
