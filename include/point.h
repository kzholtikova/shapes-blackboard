#pragma once
#include <iostream>


class Point {
public:
    static int maxX, maxY;
    int x;
    int y;

    Point(int x, int y);
    static bool areValidCoordinates(int x, int y);
    std::string toString() const;
};
