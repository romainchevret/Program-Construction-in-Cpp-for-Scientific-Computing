#include "bottomCurve.hpp"
#include <stdexcept>
#include <math.h>
#include <iostream>

double f(double x){
    if (x >= -10 && x < -3) {
        return 1/(2*(1 + std::exp(-3 * (x + 6))));
    } else if (x >= -3 && x <= 5) {
        return 1/(2*(1 + std::exp(3 * x)));
    } else {
        throw std::out_of_range("Error : x is outside of boundaries for f");
    }
}

double fprime(double t){
    //TODO this is not the derivative of f!
    if (t >= -10 && t < -3) {
        // return -3*std::exp(3*t)/(2*(1+std::exp(3*t-18)))/(2*(1+std::exp(3*t-18)));
        return 3*std::exp(-3*(t+6))/(2*pow((std::exp(-3*(t+6))+1),2));
    } else if (t >= -3 && t <= 5) {
        // return -3*std::exp(3*t)/(2*(1+std::exp(3*t)))/(2*(1+std::exp(3*t)));
        return -3*std::exp(3*t)/(2*pow(std::exp(3*t)+1, 2));
    } else {
        throw std::out_of_range("Error : t is outside of boundaries for f");
    }
}

BottomCurve::BottomCurve(Point pointA, Point pointB) : pointA(pointA), pointB(pointB){
}

Point BottomCurve::getPointA()  { return pointA; }

Point BottomCurve::getPointB()  { return pointB; }

Point BottomCurve::gamma(double t) const{
    //t should be between 0 and 1
    double x = (1-t)*(-10)+5*t;
    double y = f(x);
    return Point(x,y);
}

Point BottomCurve::gammaprime(double t) const{
    //TODO change to the proper gradient, but how?
    double x = 15.;
    double y = 15 * fprime(-10+15*t);
    return Point(x,y);
}

