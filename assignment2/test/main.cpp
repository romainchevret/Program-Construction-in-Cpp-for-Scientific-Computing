#include "point.hpp"
#include "rectangle.hpp"
#include "quadtree.hpp"
#include "mpl_writer.hpp"
#include <iostream>
#include <vector>
#include <map>

int main() {
    std::vector<Point> points = { Point(1, 2), Point(4.2, 2.5), Point(5, 6), Point(1.3, 4.8), Point(3.42, 2.18), Point(3.1, 3.22), Point(4.1, 4.1), Point(4.3, 3.1) };
    int bucketCapacity = 2;
    Quadtree quadtree(points, bucketCapacity);
    std::map<Quadtree*, std::vector<Point>> leafPoints;
    quadtree.getPointsByLeaf(leafPoints);
    std::vector<Rectangle> rectangles;
    quadtree.getRectangles(rectangles);
    sf::MplWriter<Point, Rectangle> writer("../test/plot.py");

    for (const auto& pair : leafPoints) {
        writer << pair.second;
    }

    for (const auto& rect : rectangles) {
        writer << rect;
    }

}
