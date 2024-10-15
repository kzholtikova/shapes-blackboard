#include "../include/circle.h"


Circle::Circle(int id, bool filled, const std::string& color, std::vector<int> params)
        : Shape(id, params[0], params[1], filled, color), radius(params[2]) {
    Circle::validateParameters({ params[2] });
};

void Circle::validateParameters(const std::vector<int> &parameters) {
    if (2 * parameters[0] > std::max(Point::maxX, Point::maxY))
        throw std::invalid_argument("Radius is out of bonds.");
}

std::vector<Point> Circle::getPoints() const {
    std::vector<Point> points;
    for (int y = -radius; y <= radius; y++) {
        int offset = y == 0 ? 0 : 1;
        for (int x = -radius + abs(y) - offset; x <= radius - abs(y) + offset; x++) {
            if ((filled || abs(x) == radius - abs(y) + offset || y == -radius || y == radius)
                && Point::areValidCoordinates(vertice.x + x, vertice.y + y))
                    points.emplace_back(vertice.x + x, vertice.y + y);
        }
    }
    return points;
}

std::string Circle::toString() {
    return Shape::toString() + std::to_string(radius);
}

std::string Circle::getType() const {
    return "circle";
}
