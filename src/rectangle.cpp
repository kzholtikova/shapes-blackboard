#include "../include/rectangle.h"


Rectangle::Rectangle(bool filled, std::string color, std::vector<int> params) : Shape(params[0], params[1], filled, color), width(params[2]), length(params[3]) {
    // !!!!!
};

void Rectangle::draw(grid& grid) {
    std::shared_ptr<Shape> self = shared_from_this();

    for (int i = 0; i < width + 1; i++) {
        if (vertice.x + i < grid[0].size()) {
            grid[vertice.y][vertice.x + i].emplace_back(self);
            if (length != 0 && vertice.y + length < grid.size())
                grid[vertice.y + length][vertice.x + i].emplace_back(self);
        }
    }

    for (int i = 1; i < length; i++) {
        if (vertice.y + i < grid.size()) {
            grid[vertice.y + i][vertice.x].emplace_back(self);
            if (width != 0 && vertice.x + width < grid[0].size())
                grid[vertice.y + i][vertice.x + width].emplace_back(self);
        }
    }
}

std::string Rectangle::toString() {
    return "rectangle " + vertice.toString() + " " + std::to_string(width) + " " + std::to_string(length);
}

std::string Line::toString() {
    return "line " + vertice.toString() + " " + std::to_string(width != 0 ? 0 : 90) + " " + std::to_string(width != 0 ? width : length);
}
