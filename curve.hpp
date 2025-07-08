#pragma once
#include "point.hpp"

class Curve {
public:
virtual ~Curve() = default;
virtual Point at(double t) const = 0;
};