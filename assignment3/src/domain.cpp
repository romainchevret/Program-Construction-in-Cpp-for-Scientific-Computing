#include "domain.hpp"
#include "bottomCurve.hpp"
#include <fstream>
#include <iomanip>
#include <iostream>


Domain::Domain(){
    sides[0] = std::make_unique<BottomCurve>(Point(-10, 0), Point(5, 0));
    sides[1] = std::make_unique<Straightline>(Point(5, 0), Point(5, 3));
    sides[2] = std::make_unique<Straightline>(Point(-10, 3), Point(5, 3));
    sides[3] = std::make_unique<Straightline>(Point(-10, 0), Point(-10, 3));
}

Domain::Domain(std::array<std::unique_ptr<Curve>, 4>): sides(){}

void Domain::generateGrid(int n, std::vector<std::vector<double>>& x_grid, std::vector<std::vector<double>>& y_grid){
    double h = 1.0/n;
    x_grid.resize(n+1, std::vector<double>(n+1));
    y_grid.resize(n+1, std::vector<double>(n+1));
    for (int i = 0; i <= n; ++i) {
        double u = i * h;
        for (int j = 0; j <= n; ++j) {
            double v = j * h;
            Point proj_b = sides[0]->at(u);
            Point proj_t = sides[2]->at(u);
            Point proj_l = sides[3]->at(v);
            Point proj_r = sides[1]->at(v);
            x_grid[i][j] = ((1 - v) * proj_b.x + v * proj_t.x + (1 - u) * proj_l.x + u * proj_r.x)/2;
            y_grid[i][j] = ((1 - v) * proj_b.y + v * proj_t.y + (1 - u) * proj_l.y + u * proj_r.y)/2;
                
        }
    }
}

void Domain::writeGridToFile(const std::vector<std::vector<double>>& grid, const std::string& filename) {
    std::ofstream file(filename);

    for (const auto& row : grid) {
        for (size_t j = 0; j < row.size(); ++j) {
            file << row[j];
            if (j != row.size() - 1) {
                file << " ";
            }
        }
        file << "\n";
    }
    file.close();
}
