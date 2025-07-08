#include "rectangle.hpp"

Rectangle::Rectangle(Point bottomLeft, Point topRight) : bottomLeft(bottomLeft), topRight(topRight) {
}

bool Rectangle::intersects(const Rectangle& other) const {
    return !(other.bottomLeft.x > topRight.x || other.topRight.x < bottomLeft.x ||
             other.bottomLeft.y > topRight.y || other.topRight.y < bottomLeft.y);
}

bool Rectangle::contains(const Point& point) const {
        return (point.x >= bottomLeft.x && point.x <= topRight.x &&
                point.y >= bottomLeft.y && point.y <= topRight.y);
    }
