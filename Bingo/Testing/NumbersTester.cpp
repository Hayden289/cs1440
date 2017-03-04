//
// Created by Hayden Nielsen on 2/28/17.
//

#include "NumbersTester.h"
#include "../Numbers.h"

#include <iostream>

void NumbersTester::testConstructorAndGetter()
{
    std::cout << std::endl  << "Test Suite: NumbersTester::testConstructorAndGetter" << std::endl;
    
    {
        std::cout << "Test case 1" << std::endl;

        Numbers numbers(5, 50);
        std::vector<std::vector<int>> nums;
        numbers.getNumbers(nums);

        if (nums.size() != 5) {
            std::cout << "Failure in constructor: unexpected size for getNumbers of " << nums.size() << std::endl;
            return;
        }
        
        for (std::vector<int> i : nums) {
            if (i.size() != 5) {
                std::cout << "Failure in constructor: unexpected row size of " << i.size() << std::endl;
                return;
            }
        }

    }
}