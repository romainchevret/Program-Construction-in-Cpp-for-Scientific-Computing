#pragma once
#include "point.hpp"
#include "rectangle.hpp"
#include <vector>
#include <memory>
#include <map>

class Quadtree{
    int bucketCapacity;
    std::vector<Point> pointsCollection;
    Quadtree* NW;
    Quadtree* NE;
    Quadtree* SW;
    Quadtree* SE;
    bool isLeaf = false;
    bool isRoot = true;
    Rectangle boundaryRec;
public:
    Quadtree(std::vector<Point> pointsCollection, int bucketCapacity, bool isRoot = true, Rectangle boundary = Rectangle());
    void getPointsByLeaf(std::map<Quadtree*, std::vector<Point>>& leafPoints);
    void getRectangles(std::vector<Rectangle>& rectangles);
    ~Quadtree();
    std::vector<Point> query(const Rectangle& range) const;
};