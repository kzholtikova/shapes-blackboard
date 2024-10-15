#include "../include/rectangle.h"


Rectangle::Rectangle(int id, bool filled, const std::string& color, std::vector<int> params)
        : Shape(id, params[0], params[1], filled, color), width(params[2]), length(params[3]) {
    Rectangle::validateParameters({ params[2], params[3] });
}

void Rectangle::validateParameters(const std::vector<int> &parameters) {
    if (parameters[0] > Point::maxX || parameters[1] > Point::maxY)
        throw std::invalid_argument("Size is out of bounds.");
}

std::vector<Point> Rectangle::getPoints() const {
    std::vector<Point> points;
    for (int y = 0; y <= length; y++) {
        for (int x = 0; x <= width; x++) {
            if ((filled || x == 0 || x == width || y == 0 || y == length) && Point::areValidCoordinates(vertice.x + x, vertice.y + y))
                points.emplace_back(vertice.x + x, vertice.y + y);
        }
    }
    return points;
}

std::string Rectangle::toString() {
    return Shape::toString() + std::to_string(width) + " " + std::to_string(length);
}

std::string Rectangle::getType() const {
    return "rectangle";
}
