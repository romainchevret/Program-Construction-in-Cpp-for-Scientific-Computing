#include "point.hpp"
#include "rectangle.hpp"
#include "quadtree.hpp"
#include "mpl_writer.hpp"
#include "random_points.hpp"
#include <iostream>
#include <vector>
#include <chrono>
#include <fstream>  
#include <vector>
#include <cstddef>

std::vector<size_t> linspace(size_t start, size_t end, size_t num) {
    std::vector<size_t> result;
    if (num == 0) return result;
    if (num == 1) {
        result.push_back(start);
        return result;
    }
    double step = static_cast<double>(end - start) / (num - 1);
    for (size_t i = 0; i < num; ++i) {
        result.push_back(static_cast<size_t>(start + i * step));
    }
    return result;
}

int main() {
    std::vector<size_t> bucketSizes = linspace(1, 100, 100);  
    sf::RandomPointGenerator<Point> generator;
    size_t n = 6000;

    std::ofstream csvFile("results_capacity.csv");
    csvFile << "Points,ConstructionTime,QuadtreeQueryTime,NaiveQueryTime\n";

    for (size_t bucketCapacity : bucketSizes) {
        generator.addUniformPoints(n, Point{3.0, 3.0});  
        std::vector<Point> points = generator.takePoints();

        Rectangle boundary(Point(0, 0), Point(6, 6));

        auto start = std::chrono::high_resolution_clock::now();
        Quadtree quadtree(points, bucketCapacity, true, boundary);
        auto end = std::chrono::high_resolution_clock::now();
        std::chrono::duration<double> constructionTime = end - start;

        Rectangle queryRect(Point(2.97, 2.97), Point(3.03, 3.03));

        start = std::chrono::high_resolution_clock::now();
        std::vector<Point> foundPointsQuadtree = quadtree.query(queryRect);
        end = std::chrono::high_resolution_clock::now();
        std::chrono::duration<double> queryTimeQuadtree = end - start;

        csvFile << bucketCapacity << "," 
                << constructionTime.count() << "," 
                << queryTimeQuadtree.count() << "\n" ;
    }

    csvFile.close();
    std::cout << "The results were saved in 'results_capacity.csv'.\n";

    return 0;
}

