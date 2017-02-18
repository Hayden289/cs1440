//
// Created by Stephen Clyde on 2/3/17.
//

#include "UtilsTester.h"

#include <iostream>
#include <cmath>

#include "../Utils.h"

void UtilsTester::testSplit()
{
    std::cout << "Execute UtilsTester::testSplit" << std::endl;

    // Check good cases

    std::string pieces[20];
    std::string lineToSplit = "ABC,DEF,GHI";
    if (split(lineToSplit, ',', pieces, 3)) {
        if (pieces[0] != "ABC" || pieces[1] != "DEF" || pieces[2] != "GHI") {
            std::cout << "Failure in split(lineToSplit, ',', pieces, 3) for lineToSplit=\""
                      << lineToSplit << "\": pieces not as expected" << std::endl;
            return;
        }
    } else {
        std::cout << "Failure in split(lineToSplit, ',', pieces, 3) for lineToSplit=\""
                  << lineToSplit << "\": result value not as expected" << std::endl;
        return;
    }

    lineToSplit = "ABCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCC,D,E";
    if (split(lineToSplit, ',', pieces, 3)) {
        if (pieces[0] != "ABCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCC" || pieces[1] != "D" || pieces[2] != "E") {
            std::cout << "Failure in split(lineToSplit, ',', pieces, 3) for lineToSplit=\""
                      << lineToSplit << "\": pieces not as expected" << std::endl;
            return;
        }
    } else {
        std::cout << "Failure in split(lineToSplit, ',', pieces, 3) for lineToSplit=\""
                  << lineToSplit << "\": result value not as expected" << std::endl;
        return;
    }

    lineToSplit = "ABCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCDDDDDDDDDD";
    if (split(lineToSplit, ',', pieces, 1)) {
        if (pieces[0] != "ABCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCDDDDDDDDDD" || pieces[1] != "D" || pieces[2] != "E") {
            std::cout << "Failure in split(lineToSplit, ',', pieces, 1) for lineToSplit=\""
                      << lineToSplit << "\": pieces not as expected" << std::endl;
            return;
        }
    } else {
        std::cout << "Failure in split(lineToSplit, ',', pieces, 1) for lineToSplit=\""
                  << lineToSplit << "\": result value not as expected" << std::endl;
        return;
    }

    lineToSplit = "MNO,PQR,STU";
    if (split(lineToSplit, ',', pieces, 0)) {
        if (pieces[0] != "ABCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCDDDDDDDDDD" || pieces[1] != "D" || pieces[2] != "E") {
            std::cout << "Failure in split(lineToSplit, ',', pieces, 0) for lineToSplit=\""
                      << lineToSplit << "\": pieces not as expected" << std::endl;
            return;
        }
    } else {
        std::cout << "Failure in split(lineToSplit, ',', pieces, 0) for lineToSplit=\""
                  << lineToSplit << "\": result value not as expected" << std::endl;
        return;
    }

    lineToSplit = "MNO,,STU";
    if (split(lineToSplit, ',', pieces, 3)) {
        if (pieces[0] != "MNO" || pieces[1] != "" || pieces[2] != "STU") {
            std::cout << "Failure in split(lineToSplit, ',', pieces, 0) for lineToSplit=\""
                      << lineToSplit << "\": pieces not as expected" << std::endl;
            return;
        }
    } else {
        std::cout << "Failure in split(lineToSplit, ',', pieces, 0) for lineToSplit=\""
                  << lineToSplit << "\": result value not as expected" << std::endl;
        return;
    }

    // Check bad cases
    lineToSplit = "MNO,PQR,STU";
    if (split(lineToSplit, ',', pieces, 4)) {
        std::cout << "Failure in split(lineToSplit, ',', pieces, 0) for lineToSplit=\""
                  << lineToSplit << "\": result value not as expected" << std::endl;
        return;
    }
}

void UtilsTester::testConvertToDouble()
{
    std::cout << "Execute UtilsTester::testConvertToDouble" << std::endl;

    bool isValid;

    // Check good numbers

    std::string s = "123.4567";
    double result = convertStringToDouble(s, &isValid);
    if (result != 123.4567 || !isValid) {
        std::cout << "Failure in convertStringToDouble(s, &isValid) for s=\"" << s
                  << "\" result=" << result << " isValid=" << isValid << std::endl;
        return;
    }

    s = "  123.4567";
    result = convertStringToDouble(s, &isValid);
    if (result != 123.4567 || !isValid) {
        std::cout << "Failure in convertStringToDouble(s, &isValid) for s=\"" << s
                  << "\" result=" << result << " isValid=" << isValid << std::endl;
        return;
    }

    s = "123.4567  ";
    result = convertStringToDouble(s, &isValid);
    if (result != 123.4567 || !isValid) {
        std::cout << "Failure in convertStringToDouble(s, &isValid) for s=\"" << s
                  << "\" result=" << result << " isValid=" << isValid << std::endl;
        return;
    }

    s = "   123.4567  ";
    result = convertStringToDouble(s, &isValid);
    if (result != 123.4567 || !isValid) {
        std::cout << "Failure in convertStringToDouble(s, &isValid) for s=\"" << s
                  << "\" result=" << result << " isValid=" << isValid << std::endl;
        return;
    }

    s = "-123.4567";
    result = convertStringToDouble(s, &isValid);
    if (result != -123.4567 || !isValid) {
        std::cout << "Failure in convertStringToDouble(s, &isValid) for s=\"" << s
                  << "\" result=" << result << " isValid=" << isValid << std::endl;
        return;
    }

    s = "1.234567e2";
    result = convertStringToDouble(s, &isValid);
    if (result != 123.4567 || !isValid) {
        std::cout << "Failure in convertStringToDouble(s, &isValid) for s=\"" << s
                  << "\" result=" << result << " isValid=" << isValid << std::endl;
        return;
    }

    s = "12345.67e-2";
    result = convertStringToDouble(s, &isValid);
    if (result != 123.4567 || !isValid) {
        std::cout << "Failure in convertStringToDouble(s, &isValid) for s=\"" << s
                  << "\" result=" << result << " isValid=" << isValid << std::endl;
        return;
    }

    s = "INF";
    result = convertStringToDouble(s, &isValid);
    if (result != std::numeric_limits<double>::infinity() || !isValid) {
        std::cout << "Failure in convertStringToDouble(s, &isValid) for s=\"" << s
                  << "\" result=" << result << " isValid=" << isValid << std::endl;
        return;
    }

    s = "INFINITY";
    result = convertStringToDouble(s, &isValid);
    if (result != std::numeric_limits<double>::infinity() || !isValid) {
        std::cout << "Failure in convertStringToDouble(s, &isValid) for s=\"" << s
                  << "\" result=" << result << " isValid=" << isValid << std::endl;
        return;
    }

    // Check bad numbers

    s = "- 123.4567";
    result = convertStringToDouble(s, &isValid);
    if (result != 0 || isValid) {
        std::cout << "Failure in convertStringToDouble(s, &isValid) for s=\"" << s
                  << "\" result=" << result << " isValid=" << isValid << std::endl;
        return;
    }

    s = "123.45.67";
    result = convertStringToDouble(s, &isValid);
    if (result != 0 || isValid) {
        std::cout << "Failure in convertStringToDouble(s, &isValid) for s=\"" << s
                  << "\" result=" << result << " isValid=" << isValid << std::endl;
        return;
    }

    s = "A123.4567";
    result = convertStringToDouble(s, &isValid);
    if (result != 0 || isValid) {
        std::cout << "Failure in convertStringToDouble(s, &isValid) for s=\"" << s
                  << "\" result=" << result << " isValid=" << isValid << std::endl;
        return;
    }

    s = "123.4567A";
    result = convertStringToDouble(s, &isValid);
    if (result != 0 || isValid) {
        std::cout << "Failure in convertStringToDouble(s, &isValid) for s=\"" << s
                  << "\" result=" << result << " isValid=" << isValid << std::endl;
        return;
    }

    s = "123.4567";
    result = convertStringToDouble(s, nullptr);
    if (result != 123.4567) {
        std::cout << "Failure in convertStringToDouble(s) for s=\"" << s
                  << "\" result=" << result << " isValid=" << isValid << std::endl;
        return;
    }
}

void UtilsTester::testForNormalCases()
{

    std::cout << "Execute UtilsTester::testForNormalCases" << std::endl;

    // Test case 1
    double d1 = 7;
    double d2 = 3;
    double margin = 2;

    bool result = approximatelyEquals(d1,d2,margin);

    if (result)
    {
        std::cout << "Unexpected result for (" << d1
                  << ", " << d2
                  << ", " << margin << ")" << std::endl;
    }

    // Test case 2
    result = approximatelyEquals(d2,d1,margin);
    if (result)
    {
        std::cout << "Unexpected result for (" << d2
                  << ", " << d1
                  << ", " << margin << ")" << std::endl;
    }

    // Test case 3
    d1 = 0.0325;
    d2 = 0.03249;
    margin = 0.001;
    result = approximatelyEquals(d1,d2,margin);
    if (!result)
    {
        std::cout << "Unexpected result for (" << d1
                  << ", " << d2
                  << ", " << margin << ")" << std::endl;
    }

    // Test case 4
    result = approximatelyEquals(d2,d1,margin);
    if (!result)
    {
        std::cout << "Unexpected result for (" << d2
                  << ", " << d1
                  << ", " << margin << ")" << std::endl;
    }
}

void UtilsTester::testForBadMargin()
{
    std::cout << "Execute UtilsTester::testForBadMargin" << std::endl;

    // Test case 1
    double d1 = 4;
    double d2 = 4;
    double margin = 0;

    bool result = approximatelyEquals(d1,d2,margin);

    if (result)
    {
        std::cout << "Unexpected result for (" << d1
                  << ", " << d2
                  << ", " << margin << ")" << std::endl;
    }

    // Test case 2
    margin = -1;
    result = approximatelyEquals(d2,d1,margin);
    if (result)
    {
        std::cout << "Unexpected result for (" << d2
                  << ", " << d1
                  << ", " << margin << ")" << std::endl;
    }
}

void UtilsTester::testForZeros()
{
    std::cout << "Execute UtilsTester::testForZeros" << std::endl;

    // Test case 1
    double d1 = 0;
    double d2 = 4;
    double margin = 0.1;

    bool result = approximatelyEquals(d1,d2,margin);

    if (result)
    {
        std::cout << "Unexpected result for (" << d1
                  << ", " << d2
                  << ", " << margin << ")" << std::endl;
    }

    // Test case 2
    result = approximatelyEquals(d2,d1,margin);
    if (result)
    {
        std::cout << "Unexpected result for (" << d2
                  << ", " << d1
                  << ", " << margin << ")" << std::endl;
    }

    // Test case 3
    result = approximatelyEquals(d1,d1,margin);
    if (!result)
    {
        std::cout << "Unexpected result for (" << d1
                  << ", " << d1
                  << ", " << margin << ")" << std::endl;
    }

    // Test case 4
    d2 = 0.0002;
    margin = 0.001;
    result = approximatelyEquals(d1,d2,margin);
    if (!result)
    {
        std::cout << "Unexpected result for (" << d2
                  << ", " << d1
                  << ", " << margin << ")" << std::endl;
    }

    // Test case 5
    result = approximatelyEquals(d2,d1,margin);
    if (!result)
    {
        std::cout << "Unexpected result for (" << d2
                  << ", " << d1
                  << ", " << margin << ")" << std::endl;
    }
}

void UtilsTester::testForMaxDouble(){
    std::cout << "Execute UtilsTester::testForMaxDouble" << std::endl;

    // Test case 1
    double d1 = std::numeric_limits<double>::max();
    double d2 = d1 - 0.002;
    double margin = 0.1;

    bool result = approximatelyEquals(d1,d2,margin);

    if (!result)
    {
        std::cout << "Unexpected result for (" << d1
                  << ", " << d2
                  << ", " << margin << ")" << std::endl;
    }

    // Test case 2
    result = approximatelyEquals(d2,d1,margin);
    if (!result)
    {
        std::cout << "Unexpected result for (" << d2
                  << ", " << d1
                  << ", " << margin << ")" << std::endl;
    }

    // Test case 3
    result = approximatelyEquals(d1,d1,margin);
    if (!result)
    {
        std::cout << "Unexpected result for (" << d1
                  << ", " << d1
                  << ", " << margin << ")" << std::endl;
    }

    // Test case 4
    d2 = d1 - 1;
    result = approximatelyEquals(d1,d2,margin);
    if (!result)
    {
        std::cout << "Unexpected result for (" << d1
                  << ", " << d2
                  << ", " << margin << ")" << std::endl;
    }

    // Test case 5
    result = approximatelyEquals(d2,d1,margin);
    if (!result)
    {
        std::cout << "Unexpected result for (" << d1
                  << ", " << d2
                  << ", " << margin << ")" << std::endl;
    }
}

void UtilsTester::testForInfinity()
{
    std::cout << "Execute UtilsTester:testForInfinity" << std::endl;

    // Test case 1
    double d1 = INFINITY;
    double d2 = 4;
    double margin = 0.1;

    bool result = approximatelyEquals(d1,d2,margin);

    if (result)
    {
        std::cout << "Unexpected result for (" << d1
                  << ", " << d2
                  << ", " << margin << ")" << std::endl;
    }

    // Test case 2
    result = approximatelyEquals(d2,d1,margin);
    if (result)
    {
        std::cout << "Unexpected result for (" << d2
                  << ", " << d1
                  << ", " << margin << ")" << std::endl;
    }

    // Test case 3
    result = approximatelyEquals(d1,d1,margin);
    if (result)
    {
        std::cout << "Unexpected result for (" << d1
                  << ", " << d1
                  << ", " << margin << ")" << std::endl;
    }
}

void UtilsTester::testForNegativeNumbers()
{
    std::cout << "Execute UtilsTester::testForNegativeNumbers" << std::endl;

    // Test case 1
    double d1 = -0.03;
    double d2 = 0.02;
    double margin = 0.01;

    bool result = approximatelyEquals(d1,d2,margin);

    if (result)
    {
        std::cout << "Unexpected result for (" << d1
                  << ", " << d2
                  << ", " << margin << ")" << std::endl;
    }

    // Test case 2
    result = approximatelyEquals(d2,d1,margin);
    if (result)
    {
        std::cout << "Unexpected result for (" << d2
                  << ", " << d1
                  << ", " << margin << ")" << std::endl;
    }

    // Test case 3
    margin = 0.06;
    result = approximatelyEquals(d1,d2,margin);
    if (!result)
    {
        std::cout << "Unexpected result for (" << d1
                  << ", " << d1
                  << ", " << margin << ")" << std::endl;
    }

    // Test case 4
    result = approximatelyEquals(d2,d1,margin);
    if (!result)
    {
        std::cout << "Unexpected result for (" << d2
                  << ", " << d1
                  << ", " << margin << ")" << std::endl;
    }

    // Test case 5
    d2 = -0.05;
    result = approximatelyEquals(d1,d2,margin);
    if (!result)
    {
        std::cout << "Unexpected result for (" << d1
                  << ", " << d2
                  << ", " << margin << ")" << std::endl;
    }

    // Test case 6
    result = approximatelyEquals(d2,d1,margin);
    if (!result)
    {
        std::cout << "Unexpected result for (" << d2
                  << ", " << d1
                  << ", " << margin << ")" << std::endl;
    }

    // Test case 7
    margin = 0.001;
    result = approximatelyEquals(d1,d2,margin);
    if (result)
    {
        std::cout << "Unexpected result for (" << d1
                  << ", " << d2
                  << ", " << margin << ")" << std::endl;
    }

}