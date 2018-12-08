#pragma once

#include "Point.hpp"
#include <algorithm> 
#include <cmath>

class Line
{
public:     
    Line() {}
    Line (Point p, Point q)
    {
        a = p.getY() - q.getY();
        b = q.getX() - p.getX();
        c = - a * p.getX() - b * p.getY();
        normalization();
    }

    void normalization();
    double dist (Point p) const ;
    double getA() const;
    double getB() const;
    double getC() const;

    void setA(const double new_value_a);
    void setB(const double new_value_b);
    void setC(const double new_value_c);

private:
    double a;
    double b;
    double c;

};

