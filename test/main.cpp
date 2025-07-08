#include "domain.hpp"
#include <iostream>

int main() {
    int n = 5;
    Domain domain;
    std::vector<std::vector<double>> x_grid, y_grid;

    domain.generateGrid(n, x_grid, y_grid);

    domain.writeGridToFile(x_grid, "x_grid.txt");
    domain.writeGridToFile(y_grid, "y_grid.txt");

}
