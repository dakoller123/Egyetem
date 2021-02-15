#pragma once
#include <cmath>
class Point
{

public:
    double _x;
    double _y;

    Point (double x, double y)
    {
        _x = x;
        _y = y;
    }

    double distance(const Point &p) const
    {
        return 0.0;
        //return sqrt(pow(_x-p._x,2) + pow(_y-p._y,2));
    }


};
