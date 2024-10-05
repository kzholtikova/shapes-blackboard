#include "../include/triangle.h"


void Triangle::draw(grid& grid) {
    std::shared_ptr<Shape> self = shared_from_this();

    grid[vertice.y][vertice.x].emplace_back(self);
    grid[vertice.y + height][vertice.x].emplace_back(self);

    for (int i = 1; i < height + 1; i++) {
        grid[vertice.y + i][vertice.x - i].emplace_back(self);
        grid[vertice.y + i][vertice.x + i].emplace_back(self);
        if (i != vertice.y + height) {
            grid[vertice.y + height][vertice.x - i].emplace_back(self);
            grid[vertice.y + height][vertice.x + i].emplace_back(self);
        }
    }
}
