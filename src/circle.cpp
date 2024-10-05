#include "../include/circle.h"


void Circle::draw(grid& grid) {
    std::shared_ptr<Shape> self = shared_from_this();

    for (int i = 0; i < radius + 1; i++) {
        int offset = i - (i != 0 ? 1 : 0);
        if (vertice.y - i >= 0 && vertice.x - radius + offset >= 0)
            grid[vertice.y - i][vertice.x - radius + offset].emplace_back(self);

        if (vertice.y - radius + offset >= 0 && vertice.x + i < grid[0].size())
            grid[vertice.y - radius + offset][vertice.x + i].emplace_back(self);

        if (vertice.y + i < grid.size() && vertice.x + radius - offset < grid[0].size())
            grid[vertice.y + i][vertice.x + radius - offset].emplace_back(self);

        if (vertice.y + radius - offset < grid.size() && vertice.x - i >= 0)
            grid[vertice.y + radius - offset][vertice.x - i].emplace_back(self);
    }
}

void Circle::printInfo() {
    std::cout << id << " circle " << vertice.toString() << " " << radius;
}
