#include <iostream>
#include <functional>
#include "functions.hxx"

double simpsonRule(std::function<double(double)> f, double a , double b, int* counter){
    if(counter)
        *counter += 3;
    return (b - a)/6 * (f(a) + 4*f((a+b)/2) + f(b));
}

double simpsonRule2(std::function<double(double)> f, double a, double b, int* counter){
    double gamma = (a + b)/2;
    return simpsonRule(f, a, gamma, counter) + simpsonRule(f, gamma, b, counter);
}


double asiAlgo(std::function<double(double)> f, double a, double b, double tau, int* counter){
    if (tau <= 0){
        throw std::invalid_argument("The tolerance tau has to be strictly positive");
    }
    double i1 = simpsonRule(f, a, b, counter);
    double i2 = simpsonRule2(f, a, b);
    if(std::abs(i1 - i2) < 15*tau){
        return i2;
    }
    double mid = (a+b)/2;
    tau = tau/2;
    return asiAlgo(f, a, mid, tau, counter) + asiAlgo(f, mid, b, tau, counter);
}