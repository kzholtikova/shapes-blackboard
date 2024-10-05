#include "../include/circle.h"


void Circle::draw(grid& grid) {
    std::shared_ptr<Shape> self = shared_from_this();

    std::cout << vertice.x - radius << std::endl;
    grid[vertice.y][vertice.x - radius].emplace_back(self);
    grid[vertice.y][vertice.x + radius].emplace_back(self);
    grid[vertice.y - radius][vertice.x].emplace_back(self);
    grid[vertice.y + radius][vertice.x].emplace_back(self);

    for (int i = 0; i < radius; i++) {
        grid[vertice.y - i - 1][vertice.x - radius + i].emplace_back(self);
        grid[vertice.y - i - 1][vertice.x + radius - i].emplace_back(self);
        grid[vertice.y + i + 1][vertice.x - radius + i].emplace_back(self);
        grid[vertice.y + i + 1][vertice.x + radius - i].emplace_back(self);
    }
}
