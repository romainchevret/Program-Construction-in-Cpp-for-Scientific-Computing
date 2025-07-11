#include "equation_curve.hpp"
#include "newton.hpp"
#include <boost/math/quadrature/trapezoidal.hpp>
#include <iostream>
#include <functional>

Point EquationCurve::at(double t) const {
    auto it = container.find(t);
    if (it != container.end()) {
            return it->second;
        }
    auto gammaFunc = [this](double t) { return this->gamma(t); };
    auto gammaPrimeFunc = [this](double t) { return this->gammaprime(t); };
    double x = newton(1e-6, t, gammaFunc, gammaPrimeFunc);
    Point new_gamma = this->gamma(x);
    container[t] = new_gamma;
    return new_gamma;
}
