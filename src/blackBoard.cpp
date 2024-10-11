#include "../include/blackBoard.h"
#include <fstream>


std::map<std::string, std::string> BlackBoard::colors = {
        {"white", "37"},
        {"red", "31"},
        {"green", "32"},
        {"yellow", "33"},
        {"blue", "34"},
        {"magenta", "35"},
};

BlackBoard::BlackBoard(int width, int length) {
    Point::maxX = width - 1;
    Point::maxY = length - 1;
    boardGrid = grid(length, std::vector<std::vector<std::weak_ptr<Shape>>>(width));
}

bool BlackBoard::isEmpty() const {
    return shapes.empty();
}

void BlackBoard::draw() {
    for (auto& col : boardGrid) {
        for (auto& cell : col) {
            bool printed = false;
            while (!cell.empty()) {
                if (auto shape = cell.back().lock()) {
                    std::string color = shape->getColor();
                    std::cout << "\033[" + colors[color] + "m" + color.front() + "\033[0m";
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
