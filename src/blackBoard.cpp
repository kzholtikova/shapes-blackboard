#include "../include/blackBoard.h"
#include <fstream>


BlackBoard::BlackBoard(int width, int length) : boardGrid(width, length) {
    Point::maxX = width - 1;
    Point::maxY = length - 1;
}

std::unique_ptr<Grid> BlackBoard::getGrid() const {
    return std::make_unique<Grid>(boardGrid);
}

std::weak_ptr<Shape> BlackBoard::getSelectedShape() const {
    return selectedShape;
}

bool BlackBoard::isEmpty() const {
    return shapes.empty();
}

void BlackBoard::clear() {
   shapes.erase(shapes.begin(), shapes.end());
}

void BlackBoard::addShape(const std::shared_ptr<Shape>& shape) {
    shapes.emplace_back(shape);
    boardGrid.addShapePoints(shape);
    selectedShape = shape;
}

void BlackBoard::replaceSelectedShape(const std::shared_ptr<Shape> &shape) {
    shapes[findShapeIndex(shape->getId())] = shape;
    selectedShape = shape;
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
