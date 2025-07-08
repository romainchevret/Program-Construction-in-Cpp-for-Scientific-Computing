#include <functional>

double newton(double eps, double s, const std::function<Point(double)>& f, const std::function<Point(double)>& fp);