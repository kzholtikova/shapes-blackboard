#include "../include/rectangle.h"


void Rectangle::draw(grid& grid) {
    std::shared_ptr<Shape> self = shared_from_this();

    for (int i = 0; i < width + 1; i++) {
        grid[vertice.y][vertice.x + i].emplace_back(self);
        if (length != 0)
            grid[vertice.y + length][vertice.x + i].emplace_back(self);
    }

    for (int i = 1; i < length; i++) {
        grid[vertice.y + i][vertice.x].emplace_back(self);
        if (width != 0)
            grid[vertice.y + i][vertice.x + width].emplace_back(self);
    }
}
