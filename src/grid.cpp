#include "../include/grid.h"


void Grid::show() {
    for (auto& col : grid) {
        for (auto& cell : col) {
            bool printed = false;
            while (!cell.empty()) {
                if (auto shape = cell.back().lock()) {
                    std::string color = shape->getColor();
                    std::cout << "\033[" + ShapeFactory::colors[color] + "m" + color.front() + "\033[0m";
                    printed = true;
                    break;
                } else
                    cell.pop_back();
            }
            if (!printed)
                std::cout << ' ';
        }
        std::cout << "\n";
    }
}

void Grid::addShapePoints(const std::shared_ptr<Shape>& shapePtr) {
    for (const Point& p : shapePtr->getPoints())
        grid[p.y][p.x].emplace_back(shapePtr);
}
//
//void Grid::removeShapePoints(const std::shared_ptr<Shape>& shape) {
//    for (const Point& p : shape->getPoints())
//        grid[p.y][p.x].erase(
//                std::find_if(grid[p.y][p.x].rbegin(), grid[p.y][p.x].rend(), [&shape](const std::weak_ptr<Shape>& weakShape) {
//                    return !weakShape.expired() && weakShape.lock() == shape;
//                }));
//}



