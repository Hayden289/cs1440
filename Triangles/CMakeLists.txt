cmake_minimum_required(VERSION 3.6)
project(Triangles)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES
               Point.cpp
               Point.h
               Edge.cpp
               Edge.h
               Triangle.cpp
               Triangle.h
               Utils.cpp
               Utils.h)
add_executable(Triangles main.cpp  ${SOURCE_FILES})

set(TEST_FILES Testing/PointTester.cpp
               Testing/PointTester.h
               Testing/EdgeTester.cpp
               Testing/EdgeTester.h
               Testing/TriangleTester.cpp
               Testing/TriangleTester.h
               Testing/UtilsTester.cpp
               Testing/UtilsTester.h)
add_executable(Test Testing/testMain.cpp ${TEST_FILES} ${SOURCE_FILES} )
