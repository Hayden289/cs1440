//
// Created by Stephen Clyde on 1/16/17.
//

#include <sstream>
#include <fstream>
#include "Utils.h"

bool split(const std::string& s, char delimiter, std::string elements[], int expectedNumberOfElements)
{
    std::stringstream ss;
    ss.str(s);
    std::string item;

    int i=0;
    while (std::getline(ss, item, delimiter) && i<expectedNumberOfElements)
    {
        elements[i++] = item;
    }
    return (i==expectedNumberOfElements);
}

std::string getTrimmedLine(std::ifstream& inputStream)
{
    std::string line = "";
    if (inputStream.is_open() && !inputStream.eof()) {
        std::getline(inputStream, line);
        line = trim(line);
    }
    return line;
}

//  Note: trim, ltrim, and rtrim were adapted from
//      http://stackoverflow.com/questions/25829143/c-trim-whitespace-from-a-string

// Removes leading and trailing whitespace, include space, tabs, newlines, and returns
std::string trim(const std::string& str) {
    return ltrim(rtrim(str));
}

// Removes leading whitespace, include space, tabs, newlines, and returns
std::string ltrim(const std::string& inputStr) {
    std::string str = inputStr;
    auto it2 =  std::find_if( str.begin() , str.end() , IsNotWhiteSpace );
    str.erase( str.begin() , it2);
    return str;
}

// Removes trailing whitespace, include space, tabs, newlines, and returns
std::string rtrim(const std::string& inputStr)
{
    std::string str = inputStr;
    auto it1 =  std::find_if( str.rbegin() , str.rend() , IsNotWhiteSpace );
    str.erase( it1.base() , str.end() );
    return str;
}

// Function to check if a character is a not a whitespace character, namely
//      space (0x20, ' ')
//      form feed (0x0c, '\f')
//      line feed (0x0a, '\n')
//      carriage return (0x0d, '\r')
//      horizontal tab (0x09, '\t')
//       vertical tab (0x0b, '\v')
bool IsNotWhiteSpace (char ch) {
    return !std::isspace<char>(ch , std::locale::classic() );
}

std::string centerString(const std::string& str, int width)
{
    std::string tmp = str;
    int strLength = (int) tmp.length();
    if (strLength>width)
        tmp.erase(width, strLength - width);
    else if (strLength<width)
    {
        int paddingLeft = (width - strLength)/2;
        int paddingRight = width - strLength - paddingLeft;
        tmp.insert(0, paddingLeft, ' ');
        tmp.append(paddingRight, ' ');
    }

    return tmp;
}