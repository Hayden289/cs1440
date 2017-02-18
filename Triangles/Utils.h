//
// Created by Stephen Clyde on 2/3/17.
//

#ifndef TRIANGLES_UTILS_H
#define TRIANGLES_UTILS_H

#include <string>
#include <fstream>

bool split(const std::string& s, char delimiter, std::string elements[], int expectedNumberOfElements);
double convertStringToDouble(const std::string& s, bool* valid);
bool approximatelyEquals(double d1, double d2, double margin);

std::string trim(const std::string& str);
std::string ltrim(const std::string& str);
std::string rtrim(const std::string& str);
bool isNotWhiteSpace(char ch);

#endif //TRIANGLES_UTILS_H
