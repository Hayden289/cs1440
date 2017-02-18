//
// Created by Stephen Clyde on 2/3/17.
//

#ifndef TRIANGLES_TRIANGLE_H
#define TRIANGLES_TRIANGLE_H

#include <string>
#include "Point.h"
#include "Edge.h"

class Triangle {
private:
    Point**     m_points;
    Edge**      m_edges;
    bool        m_isValid = false;
    double      m_edgeLengthThreshold = 0.01;

public:
    Triangle(Point** points);
    Triangle(std::string& pointsStr);
    bool isValid() const;
    bool isTriangle() const;
    char getTriangleType() const;
    double computerArea() const;

    const Point* getPoint(int index) const;

private:
    void setupEdges();

};


#endif //TRIANGLES_TRIANGLE_H
