#include "curve.hpp"
#include <unordered_map>

class EquationCurve : public Curve {
    public:
        virtual ~EquationCurve() = default;
        Point at(double t) const override;
    private:
        virtual Point gamma(double t) const = 0;
        virtual Point gammaprime(double t) const = 0;
        mutable std::unordered_map<double, Point> container;
};