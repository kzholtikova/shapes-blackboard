#include "../include/triangle.h"


Triangle::Triangle(bool filled, const std::string& color, std::vector<int> params) : Shape(params[0], params[1], filled, color), height(params[2]) {
    if (height > Point::maxY || 2 * height > Point::maxX)
        throw std::invalid_argument("Height is out of bounds.");
}

void Triangle::draw(grid& grid) {
    std::shared_ptr<Shape> self = shared_from_this();

    grid[vertice.y][vertice.x].emplace_back(self);
    if (vertice.y + height < grid.size())
        grid[vertice.y + height][vertice.x].emplace_back(self);

    for (int i = 0; i < height + 1; i++) {
        if (vertice.y + i < grid.size() && vertice.x - i >= 0)
            grid[vertice.y + i][vertice.x - i].emplace_back(self);

        if (i != 0 && vertice.y + i < grid.size() && vertice.x + i < grid[0].size())
            grid[vertice.y + i][vertice.x + i].emplace_back(self);

        if (i != vertice.y + height && vertice.y + height < grid.size()) {
            if (vertice.x - 1 >= 0)
                grid[vertice.y + height][vertice.x - i].emplace_back(self);

            if (i != 0 && vertice.x + 1 < grid[0].size())
                grid[vertice.y + height][vertice.x + i].emplace_back(self);
        }
    }
}

std::string Triangle::toString() {
   return "triangle " + vertice.toString() + " " + std::to_string(height);
}
