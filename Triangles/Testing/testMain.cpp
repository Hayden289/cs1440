#include <string>
#include <iostream>
#include <cmath>

#include "UtilsTester.h"
#include "PointTester.h"
#include "EdgeTester.h"
#include "TriangleTester.h"

int main() {

    std::cout << "Run executable test cases " << std::endl;
    std::cout << std::endl;


    std::cout << "Test Utils" << std::endl;
    UtilsTester utilsTester;
    utilsTester.testSplit();
    utilsTester.testConvertToDouble();
    utilsTester.testForNormalCases();
    utilsTester.testForZeros();
    utilsTester.testForNegativeNumbers();
    utilsTester.testForMaxDouble();
    utilsTester.testForInfinity();
    utilsTester.testForBadMargin();
    std::cout << std::endl;

    std::cout << "Test Point" << std::endl;
    PointTester pointTester;
    pointTester.testConstructorWithDoubles();
    pointTester.testIsEquivalentTo();
    pointTester.testConstructorWithStrings();
    pointTester.testInvalid();
    std::cout << std::endl;

    std::cout << "Test Edge" << std::endl;
    EdgeTester edgeTester;
    edgeTester.testEdge01();
    edgeTester.testEdge02();
    edgeTester.testParallelEdges();
    edgeTester.testNonParallelEdges();
    edgeTester.testNonLengthEdges();
    edgeTester.testBadEdges();
    std::cout << std::endl;

    std::cout << "Test Triangle" << std::endl;
    TriangleTester triangleTester;
    triangleTester.testFirstConstructor();
    triangleTester.testSecondConstructor();
    triangleTester.testEquilateralTriangles();
    triangleTester.testIsoscelesTriangles();
    triangleTester.testScaleneTriangles();
    triangleTester.testIsoscelesTriangles();
    triangleTester.testNonTriangles();
    triangleTester.testInvalid();

    return 0;
}

