//
// Created by Stephen Clyde on 2/3/17.
//

#ifndef TRIANGLES_EDGE_H
#define TRIANGLES_EDGE_H

#include "Point.h"

class Edge {
private:
    const Point*  m_point1;
    const Point*  m_point2;
    bool          m_isValid = false;
    const double  m_slopeMarginOfError = 0.01;

public:
    Edge(const Point* point1, const Point* point2);
    bool isValid() const { return m_isValid; }
    double getLength() const;
    double getSlopeX() const;
    double getSlopeY() const;
    double getSlopeZ() const;
    bool isParallelTo(const Edge& otherEdge);

    const Point* getPoint1() { return m_point1; }
    const Point* getPoint2() { return m_point2; }

private:
    bool areSlopesEquivalent(double slope1, double slope2) const;
};


#endif //TRIANGLES_EDGE_H
