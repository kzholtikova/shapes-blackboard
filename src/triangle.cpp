#include "../include/triangle.h"


Triangle::Triangle(int id, bool filled, const std::string& color, std::vector<int> params)
        : Shape(id, params[0], params[1], filled, color), height(params[2]) {
    Triangle::validateParameters({ params[2] });
}

void Triangle::validateParameters(const std::vector<int> &parameters) {
    if (parameters[0] > Point::maxY || 2 * parameters[0] > Point::maxX)
        throw std::invalid_argument("Height is out of bounds.");
}

std::vector<Point> Triangle::getPoints() const {
    std::vector<Point> points;
    for (int y = 0; y <= height; y++) {
        for (int x = -y; x <= y; ++x) {
            if ((filled || abs(x) == y || y == 0 || y == height) && Point::areValidCoordinates(vertice.x + x, vertice.y + y))
                points.emplace_back(vertice.x + x, vertice.y + y);
        }
    }
    return points;
}

std::string Triangle::toString() {
   return Shape::toString() + std::to_string(height);
}

std::string Triangle::getType() const {
    return "triangle";
}
