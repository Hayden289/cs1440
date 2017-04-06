#include <iostream>

#include "Dictionary.h"

int main() {
    Dictionary<int, std::string>* myDictionary = new Dictionary();

    myDictionary->add(5, "Towel");
    myDictionary->add(10, "Arthur Dent");
    myDictionary->add(1, "Marvin");

    std::cout << myDictionary->getByKey(1).getValue() << std::endl;

    return 0;
}