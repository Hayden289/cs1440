//
// Created by Stephen Clyde on 2/3/17.
//

#ifndef TRIANGLES_UTILSTESTER_H
#define TRIANGLES_UTILSTESTER_H


class UtilsTester {

public:
    // Test suite to split
    void testSplit();

    // Test suite for convertToDouble()
    void testConvertToDouble();

    // Test suites for approximatelyEquals()
    void testForNormalCases();
    void testForBadMargin();
    void testForZeros();
    void testForMaxDouble();
    void testForInfinity();
    void testForNegativeNumbers();
};


#endif //TRIANGLES_UTILSTESTER_H
