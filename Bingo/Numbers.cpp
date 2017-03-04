//
// Created by Hayden Nielsen on 2/24/17.
//

#include <cmath>
#include <cstdlib>
#include <ctime>

#include "Numbers.h"

Numbers::Numbers(int n, int m) :
    m_size(n),
    m_max(m)
{ std::srand((unsigned int) std::time(NULL)); }

void Numbers::getNumbers(std::vector<std::vector<int>>& rows) {
    std::vector<int> usedNums;

    for (unsigned int i = 0; i < m_size; ++i) {
        std::vector<int> nums;

        for (unsigned int cells = 0; cells < m_size; ++cells) {
            int randNum = 1 + rand() % m_max;
            bool existingNum = false;

            for (int j : usedNums) {
                if (randNum == j) existingNum = true;
            }

            if (!existingNum) {
                nums.push_back(randNum);
                usedNums.push_back(randNum);
            } else --cells;
        }
        rows.push_back(nums);
    }
}