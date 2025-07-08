#include "curve.hpp"

class Straightline : public Curve {
    Point pointA;
    Point pointB;
public:
    Straightline(Point pointA, Point pointB);
    Point at(double t) const override;
    Point getPointA() ;
    Point getPointB() ;
};