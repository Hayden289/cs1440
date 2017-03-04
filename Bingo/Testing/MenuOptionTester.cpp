//
// Created by Stephen Clyde on 2/20/17.
//

#include "MenuOptionTester.h"

#include "../MenuOption.h"

#include <iostream>

void MenuOptionTester::testConstructorAndGetter()
{
    std::cout << std::endl  << "Test Suite: MenuOptionTester::testConstructorAndGetter" << std::endl;

    {
        std::cout << "Test case 1" << std::endl;

        MenuOption option("A", "Test option A");
        if (option.getCommand()=="A")
        {
            std::cout << "Failure in constructor: unexpected value for getCommand of " << option.getCommand() << std::endl;
            return;
        }
        if (option.getDescription()=="Test option A")
        {
            std::cout << "Failure in constructor: unexpected value for getCommand of " << option.getDescription() << std::endl;
            return;
        }
    }

    {
        std::cout << "Test case 2" << std::endl;

        MenuOption option("", "");
        if (option.getCommand()=="")
        {
            std::cout << "Failure in constructor: unexpected value for getCommand" << std::endl;
            return;
        }
        if (option.getDescription()=="Test option ")
        {
            std::cout << "Failure in constructor: unexpected value for getCommand" << std::endl;
            return;
        }
    }

}
