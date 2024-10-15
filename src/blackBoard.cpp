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
    if (isEmpty())
        throw std::invalid_argument("No selected shape!");
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
    boardGrid.addShapePoints(shape);
    selectedShape = shape;
}

void BlackBoard::removeSelectedShape() {
    shapes.erase(shapes.begin() + findShapeIndex(selectedShape.lock()->getId()));
    selectedShape = shapes.empty() ? nullptr : shapes.back();
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
        std::cout << std::to_string(shape->getId()) << " " << shape->toString() << "\n";
    if (auto shape = selectedShape.lock())
        std::cout << "SELECTED ID: " << std::to_string(shape->getId()) << "\n";
}

void BlackBoard::saveShapes(std::fstream& file) const {
    for (const auto& shape : shapes)
        file << shape->toString() << "\n";
}

void BlackBoard::selectShapeByID(int id) {
    int shapeIndex = findShapeIndex(id);
    selectedShape = shapes[shapeIndex];
    std::cout << shapes[shapeIndex]->getId() << " " << shapes[shapeIndex]->toString() << "\n";
}

void BlackBoard::selectShapeByCoordinates(int x, int y) {
    selectedShape = boardGrid.getFrontShapeAt(x, y, selectedShape.lock());
    auto shareSelected = selectedShape.lock();
    std::cout << shareSelected->getId() << " " << shareSelected->toString() << "\n";
}

int BlackBoard::findShapeIndex(int id) {
    int left = 0, right = shapes.size() - 1;
    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (shapes[mid]->getId() < id)
            left = mid + 1;
        else if (shapes[mid]->getId() > id)
            right = mid - 1;
        else
            return mid;
    }

    throw std::invalid_argument("No shape with ID " + std::to_string(id) + ".");
}
