#include "point.hpp"
#include <cmath>

Point::Point(){
    x = 0;
    y = 0; 
}
Point::Point(double xCoord, double yCoord) : x(xCoord), y(yCoord){
}

double Point::norm(){
    return std::sqrt(x*x + y*y);
}