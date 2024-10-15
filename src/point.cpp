#include "../include/point.h"


int Point::maxX, Point::maxY = -1;

std::string Point::toString() const {
    return std::to_string(x) + " " + std::to_string(y);
}

Point::Point(int x, int y) : x(x), y(y) {
    if (!areValidCoordinates(x, y))
        throw std::invalid_argument("Point is out of board.");
}

bool Point::areValidCoordinates(int x, int y) {
    return x >= 0 && x <= maxX && y >= 0 && y <= maxY;
}
