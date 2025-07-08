#include <chrono>
#include <iostream>
#include <vector>
#include <fstream>
#include "domain.hpp"

int main(){
    std::vector<std::vector<double>> x_grid, y_grid;
    std::chrono::duration<double> duration;
    std::ofstream perf_file;
    perf_file.open("perf_no_container.txt");
    Domain domain;
    for (int n=5;n<200;n++){
        std::cout<<n<<std::endl;
        auto start = std::chrono::high_resolution_clock::now();
        domain.generateGrid(n, x_grid, y_grid);
        auto end = std::chrono::high_resolution_clock::now();

        duration = end - start;
        perf_file << n << " " << duration.count() << "\n";
        x_grid.clear();
        y_grid.clear();
    }
    perf_file.close();
}
