#include <iostream>
#include "Triangle.h"

int main() {

    std::string userInput;
    bool keepGoing = true;
    while (keepGoing)
    {
        std::cout << "Enter a triangle, in the x1,y1,z1|x2,y2,z2|x3,y3,z3 format, or EXIT?" << std::endl;
        std::cin >> userInput;
        if (userInput=="EXIT")
        {
            keepGoing = false;
        }
        else
        {
            Triangle triangle(userInput);
            std::cout << "Type = " << triangle.getTriangleType() << std::endl;
            std::cout << "Area = " << triangle.computerArea() << std::endl;
            std::cout << std::endl;
        }


    }
    return 0;
}