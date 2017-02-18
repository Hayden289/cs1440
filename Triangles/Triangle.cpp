//
// Created by Stephen Clyde on 2/3/17.
//

#include "Triangle.h"
#include "Utils.h"

#include <cmath>

Triangle::Triangle(Point** points) : m_points(points)
{
    setupEdges();
}

Triangle::Triangle(std::string& triangleStr)
{
    std::string values[3];
    if (split(triangleStr, '|', values, 3))
    {
        m_points = new Point*[3];
        m_points[0] = new Point(values[0]);
        m_points[1] = new Point(values[1]);
        m_points[2] = new Point(values[1]);
        setupEdges();
    }
}

bool Triangle::isValid() const
{
    return m_isValid;
}

bool Triangle::isTriangle() const
{
    bool result = false;

    // Make sure the points are valid
    if (m_isValid)
    {

        // Make sure all of the points are different
        if (!m_points[0]->isEquivalentTo(*(m_points[1])) &&
            !m_points[1]->isEquivalentTo(*(m_points[2])) &&
            !m_points[2]->isEquivalentTo(*(m_points[0])))
        {
            // Make sure the edges are non-parallel
            if (!m_edges[0]->isParallelTo(*(m_edges[1])) &&
                !m_edges[1]->isParallelTo(*(m_edges[2])) &&
                !m_edges[2]->isParallelTo(*(m_edges[0])))
            {
                result = true;
            }
        }
    }

    return result;
}

char Triangle::getTriangleType() const
{
    char result = 'X';
    if (isValid())
    {
        if (!isTriangle())
        {
            double a = m_edges[0]->getLength();
            double b = m_edges[1]->getLength();
            double c = m_edges[2]->getLength();
            // If all three side are the same, then its an equilateral
            if (approximatelyEquals(a, b, m_edgeLengthThreshold)  && approximatelyEquals(b, c, m_edgeLengthThreshold)) {
                result = 'E';
            }
            // If any two sides are the same, then its an isosceles
            else if (approximatelyEquals(a, b, m_edgeLengthThreshold) ||
                    approximatelyEquals(b, c, m_edgeLengthThreshold) ||
                    approximatelyEquals(c, c, m_edgeLengthThreshold))
            {
                result = 'I';
            }
            // Otherwise its an scalene
            else
            {
                result = 'S';
            }
        }
        else
        {
            result = 'N';
        }
    }
    return result;
}

double Triangle::computerArea() const
{
    double area = 0;

    if (isTriangle())
    {
        // Use Heron's to calculate the area
        // see https://www.mathsisfun.com/geometry/herons-formula.html
        double a = m_edges[0]->getLength();
        double b = m_edges[1]->getLength();
        double c = m_edges[2]->getLength();
        double s = ( a + b + b)/2;
        area = sqrt(s*(s-a)*(s-b)*(s-c));
    }
    return area;
}

const Point* Triangle::getPoint(int index) const
{
    Point* result = nullptr;

    if (isValid() && index>=0 && index<3)
        result = m_points[index];

    return result;
}

void Triangle::setupEdges()
{
    m_isValid = false;
    if (m_points!= nullptr &&
        m_points[0] != nullptr && m_points[1] != nullptr && m_points[2] != nullptr &&
        m_points[0]->isValid() && m_points[1]->isValid() && m_points[2]->isValid())
    {
        m_edges = new Edge*[3];
        m_edges[0] = new Edge(m_points[0], m_points[1]);
        m_edges[1] = new Edge(m_points[1], m_points[2]);
        m_edges[2] = new Edge(m_points[2], m_points[0]);

        m_isValid = m_edges[0]->isValid() || m_edges[1]->isValid() || m_edges[2]->isValid();
    }
}