#include "quadtree.hpp"
#include <vector>
#include <iostream>
#include <map>

Quadtree::Quadtree(std::vector<Point> pointsCollection, int bucketCapacity, bool isRoot, Rectangle boundary){
    this->bucketCapacity = bucketCapacity;
    if(pointsCollection.size() <= bucketCapacity){
        isLeaf = true;
        this->pointsCollection = pointsCollection;
        this->boundaryRec = boundary;
        NW = nullptr;
        SW = nullptr;
        NE = nullptr;
        SE = nullptr;
        return;
    }
    double xMax;
    double yMax;
    double xMin;
    double yMin;
    std::vector<std::vector<Point>> subDivisions(4);
    if(isRoot){
        xMax = pointsCollection[0].x;
        yMax = pointsCollection[0].y;
        xMin = pointsCollection[0].x;
        yMin = pointsCollection[0].y;
        // Loop to find the first rectangle
        for(const Point& point : pointsCollection){
            if (point.x > xMax){
                xMax = point.x;
            }
            if (point.y > yMax){
                yMax = point.y;
            }
            if (point.x < xMin){
                xMin = point.x;
            }
            if (point.y < yMin){
                yMin = point.y;
            }
        }
        boundaryRec = Rectangle(Point(xMin, yMin), Point(xMax, yMax));
    }
    else{
        xMin = boundary.bottomLeft.x;
        xMax = boundary.topRight.x;
        yMin = boundary.bottomLeft.y;
        yMax = boundary.topRight.y;
        boundaryRec = Rectangle(Point(xMin, yMin), Point(xMax, yMax));
    }
    
    for(const Point& point : pointsCollection){
        int idx = 0;
        if(point.x > (xMax+xMin)/2){
            idx++;
        }
        if (point.y < (yMax + yMin)/2){
            idx+=2;
        }
        subDivisions[idx].push_back(point);
    }
    NW = new Quadtree(subDivisions[0], bucketCapacity, false, Rectangle(Point(xMin, (yMax+yMin)/2), Point((xMax + xMin)/2, yMax)));
    NE = new Quadtree(subDivisions[1], bucketCapacity, false, Rectangle(Point((xMax + xMin)/2, (yMax + yMin)/2), Point(xMax, yMax)));
    SW = new Quadtree(subDivisions[2], bucketCapacity, false, Rectangle(Point(xMin, yMin), Point((xMax + xMin)/2, (yMax + yMin)/2)));
    SE = new Quadtree(subDivisions[3], bucketCapacity, false, Rectangle(Point((xMax+xMin)/2, yMin), Point(xMax, (yMax + yMin)/2)));
}

void Quadtree::getPointsByLeaf(std::map<Quadtree*, std::vector<Point>>& leafPoints) {
    if (isLeaf) {
        leafPoints[this] = pointsCollection;
    } else {
        if (NW != nullptr){ 
            NW->getPointsByLeaf(leafPoints);
        }
        if (NE != nullptr){ 
            NE->getPointsByLeaf(leafPoints);
        }
        if (SW != nullptr){ 
            SW->getPointsByLeaf(leafPoints);
        }
        if (SE != nullptr){ 
            SE->getPointsByLeaf(leafPoints);
        }
    }
}

void Quadtree::getRectangles(std::vector<Rectangle>& rectangles) {
    rectangles.push_back(boundaryRec);
    std::cout << boundaryRec.bottomLeft.x << std::endl;
    if (!isLeaf) {
        if (NW != nullptr) NW->getRectangles(rectangles);
        if (NE != nullptr) NE->getRectangles(rectangles);
        if (SW != nullptr) SW->getRectangles(rectangles);
        if (SE != nullptr) SE->getRectangles(rectangles);
    }
}

Quadtree::~Quadtree() {
    if (NW != nullptr) delete NW;
    if (NE != nullptr) delete NE;
    if (SW != nullptr) delete SW;
    if (SE != nullptr) delete SE;
}

std::vector<Point> Quadtree::query(const Rectangle& range) const {
        std::vector<Point> foundPoints;
        // If there is no intersection with the quadtree, there is no point to add
        if (!boundaryRec.intersects(range)) {
            return foundPoints;
        }

        //If it is a leaf, we check every point
        if (isLeaf) {
            for (const Point& point : pointsCollection) {
                if (range.contains(point)) {
                    foundPoints.push_back(point);
                }
            }
        } else {
            if (NW != nullptr) {
                std::vector<Point> nwPoints = NW->query(range);
                foundPoints.insert(foundPoints.end(), nwPoints.begin(), nwPoints.end());
            }
            if (NE != nullptr) {
                std::vector<Point> nePoints = NE->query(range);
                foundPoints.insert(foundPoints.end(), nePoints.begin(), nePoints.end());
            }
            if (SW != nullptr) {
                std::vector<Point> swPoints = SW->query(range);
                foundPoints.insert(foundPoints.end(), swPoints.begin(), swPoints.end());
            }
            if (SE != nullptr) {
                std::vector<Point> sePoints = SE->query(range);
                foundPoints.insert(foundPoints.end(), sePoints.begin(), sePoints.end());
            }
        }
        return foundPoints;
    }