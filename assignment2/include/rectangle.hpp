#pragma once
#include "point.hpp"

class Rectangle{
public:
    Point bottomLeft;
    Point topRight;
    // Rectangle();
    Rectangle() : bottomLeft(Point(0, 0)), topRight(Point(0, 0)) {}
    Rectangle(Point bottomLeft, Point topRight);
    bool intersects(const Rectangle& other) const ;
    bool contains(const Point& point) const;
};