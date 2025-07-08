#include "point.hpp"
#include "rectangle.hpp"
#include "quadtree.hpp"
#include "mpl_writer.hpp"
#include "random_points.hpp"  
#include <iostream>
#include <vector>
#include <map>

int main() {
    std::random_device rd;  
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> distrib(50, 900); 

    size_t n = distrib(gen);

    sf::RandomPointGenerator<Point> generator;

    // generates n points centered around (3.0, 3.0)
    generator.addUniformPoints(n, Point{3.0, 3.0}); 

    std::vector<Point> points = generator.takePoints();

    // We only take the points around this rectangle
    Rectangle boundary(Point(0, 0), Point(6, 6));
    int bucketCapacity = 4;  

    Quadtree quadtree(points, bucketCapacity, true, boundary);

    sf::MplWriter<Point, Rectangle> writer("../test/plot_query.py");

    writer << points;
    // Create query region
    Rectangle queryRect(Point(2.5, 2.3), Point(8.7, 3.5));

    std::vector<Point> foundPoints = quadtree.query(queryRect);

    writer << foundPoints;

    return 0;
}
