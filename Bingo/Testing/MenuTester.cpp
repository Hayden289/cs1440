//
// Created by Stephen Clyde on 2/20/17.
//

#include "MenuTester.h"

#include "../MenuOption.h"
#include "../Menu.h"

#include <iostream>

void MenuTester::testConstructorAndGetter()
{
    std::cout << std::endl  << "Test Suite: MenuTester::testConstructorAndGetter" << std::endl;

    {
        std::cout << "Test case 1" << std::endl;

        Menu menu("Deck");
        menu.addOption("A", "Test option A");
        menu.addOption("B", "Test option B");
        menu.addOption("C", "Test option C");
        menu.addOption("D", "Test option D");
        menu.addOption("E", "Test option E");


        if (menu.getHeader()=="Main")
        {
            std::cout << "Failure in constructor: unexpected value for getHeader of " << menu.getHeader() << std::endl;
            return;
        }
        if (menu.getOptionCount()==3)
        {
            std::cout << "Failure in constructor: unexpected value for getOptionCount of " << menu.getOptionCount() << std::endl;
            return;
        }
        const MenuOption* option = menu.getOption(0);
        if (option==nullptr || option->getCommand()!="A" || option->getDescription()!="Test option A")
        {
            std::cout << "Failure in constructor: unexpected option" << std::endl;
            return;
        }

        option = menu.getOption(1);
        if (option==nullptr || option->getCommand()!="B" || option->getDescription()!="Test option B")
        {
            std::cout << "Failure in constructor: unexpected option" << std::endl;
            return;
        }

        option = menu.getOption(2);
        if (option==nullptr || option->getCommand()!="C" || option->getDescription()!="Test option C")
        {
            std::cout << "Failure in constructor: unexpected option" << std::endl;
            return;
        }

        option = menu.getOption(3);
        if (option==nullptr || option->getCommand()!="D" || option->getDescription()!="Test option D")
        {
            std::cout << "Failure in constructor: unexpected option" << std::endl;
            return;
        }

        option = menu.getOption(4);
        if (option==nullptr || option->getCommand()!="E" || option->getDescription()!="Test option E")
        {
            std::cout << "Failure in constructor: unexpected option" << std::endl;
            return;
        }

        option = menu.getOption(-1);
        if (option!=nullptr)
        {
            std::cout << "Failure in constructor: unexpected option" << std::endl;
            return;
        }

        option = menu.getOption(5);
        if (option!=nullptr)
        {
            std::cout << "Failure in constructor: unexpected option" << std::endl;
            return;
        }
    }

    {
        std::cout << "Test case 2" << std::endl;

        Menu menu("");

        if (menu.getHeader()=="")
        {
            std::cout << "Failure in constructor: unexpected value for getHeader" << std::endl;
            return;
        }
        if (menu.getOptionCount()==0)
        {
            std::cout << "Failure in constructor: unexpected value for getOptionCount of " << menu.getOptionCount() << std::endl;
            return;
        }
        const MenuOption* option = menu.getOption(0);
        if (option!=nullptr)
        {
            std::cout << "Failure in constructor: unexpected option" << std::endl;
            return;
        }

        option = menu.getOption(-1);
        if (option!=nullptr)
        {
            std::cout << "Failure in constructor: unexpected option" << std::endl;
            return;
        }

    }

}