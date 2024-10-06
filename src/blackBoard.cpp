#include "../include/blackBoard.h"
#include <fstream>


BlackBoard::BlackBoard() {
    width = 165, length = 10;
    shapeFactory = std::make_unique<ShapeFactory>(width, length);
    boardGrid = grid(length, std::vector<std::vector<std::weak_ptr<Shape>>>(width));
}

ShapeFactory* BlackBoard::getShapeFactory() const {
    return shapeFactory.get();
}

bool BlackBoard::isEmpty() const {
    return shapes.empty();
}

void BlackBoard::draw() const {
    for (auto& col : boardGrid) {
        for (auto& cell : col) {
            bool printed = false;
            for (auto it = cell.rbegin(); it != cell.rend(); ++it) {
                if (auto shape = it->lock()) {
                    std::cout << shape->getId();
                    printed = true;
                    break;
                }
            }
            if (!printed)
                std::cout << ' ';
        }
        std::cout << "\n";
    }
}

void BlackBoard::clear() {
   shapes.erase(shapes.begin(), shapes.end());
}

void BlackBoard::addShape(const std::shared_ptr<Shape>& shape) {
    shapes.emplace_back(shape);
    shape->draw(boardGrid);
}

void BlackBoard::removeLastShape() {
    shapes.pop_back();
}

void BlackBoard::listShapes() const {
    for (const auto& shape : shapes)
        std::cout << shape->toString();
}

void BlackBoard::saveShapes(std::fstream& file) const {
    for (const auto& shape : shapes)
        file << shape->toString() << "\n";
}
