#include "../include/grid.h"


void Grid::show(const std::shared_ptr<Shape>& selected) {
    for (auto& col : grid) {
        for (auto& cell : col) {
            std::shared_ptr<Shape> lastValidShape = nullptr;
            auto it = std::find_if(cell.rbegin(), cell.rend(), [&](const std::weak_ptr<Shape>& weakShape) {
                if (auto shape= weakShape.lock()) {
                    lastValidShape = shape;
                    return !selected || shape == selected;
                }
                return false;
            });

            if (!lastValidShape)
                std::cout << ' ';
            else
                std::cout << "\033[" + ShapeFactory::colors[lastValidShape->getColor()] + "m" + lastValidShape->getColor().front() + "\033[0m";
        }
        std::cout << "\n";
    }
}

void Grid::addShapePoints(const std::shared_ptr<Shape>& shapePtr) {
    for (const Point& p : shapePtr->getPoints())
        grid[p.y][p.x].emplace_back(shapePtr);
}

std::weak_ptr<Shape> Grid::getFrontShapeAt(int x, int y, const std::shared_ptr<Shape>& selected) {
    std::shared_ptr<Shape> lastValidShape = nullptr;
    auto it = std::find_if(grid[y][x].rbegin(), grid[y][x].rend(), [&](const std::weak_ptr<Shape>& weakShape) {
        if (auto shape= weakShape.lock()) {
            lastValidShape = shape;
            return !selected || shape == selected;
        }
        return false;
    });

    if (lastValidShape)
        return lastValidShape;
    throw std::invalid_argument("No shapes at (" + std::to_string(x) + "; " + std::to_string(y) + ").");
}
