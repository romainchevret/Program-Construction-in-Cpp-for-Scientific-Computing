#ifndef FUNCTIONS_HXX
#define FUNCTIONS_HXX

#include <functional>

double simpsonRule(std::function<double(double)> f, double a, double b, int* counter = nullptr);

double simpsonRule2(std::function<double(double)> f, double a, double b, int* counter = nullptr);

double asiAlgo(std::function<double(double)> f, double a, double b, double tau, int* counter = nullptr);

#endif