#include <cmath>
#include <iostream>
#include <fstream>
#include <functional>
#include <boost/math/quadrature/trapezoidal.hpp>
#include "point.hpp"

double integrateNormFp(const std::function<Point(double)>& fp, double start, double end) {
    auto integrand = [&fp](double t) {
        return fp(t).norm();
    };
    return boost::math::quadrature::trapezoidal(integrand, start, end, 1e-6); 
}

double newton(double eps, double s, const std::function<Point(double)>& f, const std::function<Point(double)>& fp){
    //TESTME
    // Point fx = f(0.5);
    // Point fxd = fp(0.5);
    double x = 0.5;
    double arc_length = integrateNormFp(fp, 0, 1);
    double f_norm = integrateNormFp(fp, 0, x);
    while(std::abs(f_norm - s * arc_length) >= eps){
        f_norm = integrateNormFp(fp, 0, x);
        double adjustment = (f_norm - s * arc_length) / fp(x).norm();
        x -= adjustment;
        if (x < 0) x = 0;
        if (x > 1) x = 1;
    }
    return x;
}