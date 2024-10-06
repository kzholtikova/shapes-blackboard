#include "../include/blackBoard.h"
#include <fstream>


BlackBoard::BlackBoard(int width, int length) {
    shapeFactory = std::make_unique<ShapeFactory>(width - 1, length - 1);
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

bool BlackBoard::isUniqueShape(const std::shared_ptr<Shape>& newShape) {
    for (const auto& shape : shapes) {
        if (typeid(*shape) == typeid(*newShape) && shape->toString() == newShape->toString())
            return false;
    }
    return true;
}

void BlackBoard::listShapes() const {
    for (const auto& shape : shapes)
        std::cout << shape->toString() << "\n";
}

void BlackBoard::saveShapes(std::fstream& file) const {
    for (const auto& shape : shapes)
        file << shape->toString() << "\n";
}
