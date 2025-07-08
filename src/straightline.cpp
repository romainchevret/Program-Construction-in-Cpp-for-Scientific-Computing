#include "straightline.hpp"

Straightline::Straightline(Point pointA, Point pointB) : pointA(pointA), pointB(pointB){
}

Point Straightline::at(double t) const {
    double x = (1-t)*pointA.x + t*pointB.x;
    double y = (1-t)*pointA.y + t*pointB.y;
    return Point(x, y);
}

Point Straightline::getPointA()  { return pointA; }

Point Straightline::getPointB()  { return pointB; }
