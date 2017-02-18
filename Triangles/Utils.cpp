//
// Created by Stephen Clyde on 2/3/17.
//


#include <algorithm>
#include <string>
#include <sstream>
#include <fstream>
#include <cmath>
#include "Utils.h"

// Splits a string up by the specified delimiter and stores the pieces into an array of strings, and checks
// to see if the expected number of pieces were found in the string
//
// Return a true if the string was split into the expected number of pieces, otherwise a it return a false.
bool split(const std::string& s, char delimiter, std::string pieces[], int expectedNumberOfPieces)
{
    std::stringstream ss;
    ss.str(s);
    std::string item;

    int i=0;
    while (std::getline(ss, item, delimiter) && i<expectedNumberOfPieces)
    {
        pieces[i++] = item;
    }
    return (i==expectedNumberOfPieces);
}

// Converts a string to a double
//
// Return the double value represented (0 if the string is not value) and set a valid flag, if provided, if the string
// represented an acceptable double.  The valid flag is a point to a bool.  If the pointer is null, then the function
// will still try to convert the string, but it will not try to set the valid flag.
double convertStringToDouble(const std::string& s, bool* valid)
{
    double result = 0;
    if (valid!= nullptr)
        *valid = false;

    std::size_t numberOfConvertedCharacters = 0;
    if (s!="")
    {
        try {
            std::string trimmedString = trim(s);
            result = std::stod(trimmedString, &numberOfConvertedCharacters);
            if (valid!=nullptr && numberOfConvertedCharacters==trimmedString.length())
                *valid = true;
            else if (numberOfConvertedCharacters!=trimmedString.length())
                result = 0;
        }
        catch (std::exception)
        {
            // do nothing, let the result remain 0 and the valid flag false
        }
    }

    return result;
}

bool approximatelyEquals(double d1, double d2, double margin)
{
    return fabs(d1 - d2) < margin;
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
    auto it2 = std::find_if(str.begin(), str.end(), isNotWhiteSpace);
    str.erase( str.begin() , it2);
    return str;
}

// Removes trailing whitespace, include space, tabs, newlines, and returns
std::string rtrim(const std::string& inputStr)
{
    std::string str = inputStr;
    auto it1 = std::find_if(str.rbegin(), str.rend(), isNotWhiteSpace);
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
bool isNotWhiteSpace(char ch) {
    return !std::isspace<char>(ch , std::locale::classic() );
}