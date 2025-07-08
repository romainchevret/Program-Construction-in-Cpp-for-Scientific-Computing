#include "equation_curve.hpp"

class BottomCurve: public EquationCurve {
    private:
        Point pointA;
        Point pointB;
    public:
        Point gamma(double t) const override;
        Point gammaprime(double t) const override;
        BottomCurve(Point pointA, Point pointB);
        Point getPointA() ;
        Point getPointB() ;
};