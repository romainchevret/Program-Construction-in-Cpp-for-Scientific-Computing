#pragma once
#include "curve.hpp"
#include "straightline.hpp"
#include <array>
#include <vector>
#include <memory>

class Domain{
    std::array<std::unique_ptr<Curve>, 4> sides;
public:
    Domain();
    Domain(std::array<std::unique_ptr<Curve>, 4> sides);
    void generateGrid(int n, std::vector<std::vector<double>>& x_grid, std::vector<std::vector<double>>& y_grid);
    void writeGridToFile(const std::vector<std::vector<double>>& grid, const std::string& filename);
};