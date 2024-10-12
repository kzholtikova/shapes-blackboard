#include "../include/circle.h"


Circle::Circle(bool filled, const std::string& color, std::vector<int> params) : Shape(params[0], params[1], filled, color), radius(params[2]) {
    Circle::validateParameters({ params[2] });
};

void Circle::validateParameters(const std::vector<int> &parameters) {
    if (2 * parameters[0] > std::max(Point::maxX, Point::maxY))
        throw std::invalid_argument("Radius is out of bonds.");
}

std::vector<Point> Circle::getPoints() const {
//    std::shared_ptr<Shape> self = shared_from_this();
//
//    for (int i = 0; i < radius + 1; i++) {
//        int offset = i - (i != 0 ? 1 : 0);
//        if (vertice.y - i >= 0 && vertice.x - radius + offset >= 0)
//            grid[vertice.y - i][vertice.x - radius + offset].emplace_back(self);
//
//        if (vertice.y - radius + offset >= 0 && vertice.x + i < grid[0].size())
//            grid[vertice.y - radius + offset][vertice.x + i].emplace_back(self);
//
//        if (vertice.y + i < grid.size() && vertice.x + radius - offset < grid[0].size())
//            grid[vertice.y + i][vertice.x + radius - offset].emplace_back(self);
//
//        if (vertice.y + radius - offset < grid.size() && vertice.x - i >= 0)
//            grid[vertice.y + radius - offset][vertice.x - i].emplace_back(self);
//    }
}

std::string Circle::toString() {
    return getType() + ' ' + vertice.toString() + " " + std::to_string(radius);
}

std::string Circle::getType() const {
    return "circle";
}
