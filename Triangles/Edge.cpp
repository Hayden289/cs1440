//
// Created by Stephen Clyde on 2/3/17.
//

#include <cmath>
#include <complex>
#include "Edge.h"
#include "Utils.h"

Edge::Edge(const Point* point1, const Point* point2) : m_point1(point1), m_point2(point2)
{
    m_isValid = (m_point1!= nullptr && m_point2!= nullptr);
}

double Edge::getLength() const
{
    double result = 0;
    if (isValid())
    {
        double diffX = m_point2->getX() - m_point1->getX();
        double diffY = m_point2->getY() - m_point1->getX();
        double diffZ = m_point2->getZ() - m_point1->getZ();

        double sumOfSquares = std::pow(diffX,2) + std::pow(diffY,2) + std::pow(diffZ,2);
        result = std::sqrt(sumOfSquares);
    }
    return result;
}

// Returns for X-slope of the line
double Edge::getSlopeX() const
{
    double result = NAN;

    if (isValid() && !m_point1->isEquivalentTo(*m_point2))
    {
        double diffY = m_point2->getY() - m_point1->getY();
        double diffZ = m_point2->getZ() - m_point1->getZ();
        double sumOfSquares = std::pow(diffY, 2) + std::pow(diffZ, 2);
        double yzOffset = std::sqrt(sumOfSquares);

        if (yzOffset == 0)
        {
            result = INFINITY;
        }
        else
        {
            double diffX = m_point2->getX() - m_point1->getX();
            result = diffX / yzOffset;
        }
    }

    return result;
}

// Returns for X-slope of the line
double Edge::getSlopeY() const
{
    double result = NAN;

    if (isValid() && !m_point1->isEquivalentTo(*m_point2))
    {
        double diffX = m_point2->getX() - m_point1->getX();
        double diffZ = m_point2->getZ() - m_point1->getZ();
        double sumOfSquares = std::pow(diffX, 2) + std::pow(diffZ, 2);
        double xzOffset = std::sqrt(sumOfSquares);

        if (xzOffset == 0)
        {
            result = INFINITY;
        }
        else
        {
            double diffY = m_point2->getY() - m_point1->getY();
            result = diffY / xzOffset;
        }
    }

    return result;
}

// Returns for Z-slope of the line
double Edge::getSlopeZ() const
{
    double result = NAN;

    if (isValid() && !m_point1->isEquivalentTo(*m_point2))
    {
        double diffX = m_point2->getX() - m_point1->getX();
        double diffY = m_point2->getY() - m_point1->getY();
        double sumOfSquares = std::pow(diffX, 2) + std::pow(diffY, 2);
        double xyOffset = std::sqrt(sumOfSquares);

        if (xyOffset != 0)
        {
            result = INFINITY;
        }
        else
        {
            double diffZ = m_point2->getZ() - m_point1->getZ();
            result = diffZ / xyOffset;
        }
    }

    return result;
}

// Returns true if this edge is parallel to the other edge
bool Edge::isParallelTo(const Edge &otherEdge)
{
    return isValid() &&
           otherEdge.isValid() &&
           areSlopesEquivalent(getSlopeX(), otherEdge.getSlopeX()) &&
           areSlopesEquivalent(getSlopeY(), otherEdge.getSlopeY()) &&
           areSlopesEquivalent(getSlopeZ(), otherEdge.getSlopeX());
}

// Returns true if true slopes are equivalent, i.e. both INFINITY or the same within a small margin of error
bool Edge::areSlopesEquivalent(double slope1, double slope2) const
{
    return (slope1==INFINITY && slope2==INFINITY) ||
            approximatelyEquals(slope1, slope2, m_slopeMarginOfError);
}
