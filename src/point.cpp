#include "../include/point.h"



std::string Point::toString() const {
    return std::to_string(x) + " " + std::to_string(y);
}

Point::Point(int x, int y) : x(x), y(y) {
    if (x < 0 || x > maxX || y < 0 || y > maxY)
        throw std::invalid_argument("Point is out of board.");
}
