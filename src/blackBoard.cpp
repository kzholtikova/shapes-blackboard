#include "../include/blackBoard.h"


BlackBoard::BlackBoard() {
    width = 165, length = 10;
    shapeFactory = std::make_unique<ShapeFactory>(width, length);
    boardGrid = grid(length, std::vector<std::vector<std::weak_ptr<Shape>>>(width));
}

ShapeFactory* BlackBoard::getShapeFactory() const {
    return shapeFactory.get();
}

void BlackBoard::draw() const {
    for (auto& col : boardGrid) {
        for (auto& cell : col)
            std::cout << (!cell.empty() ? '*' : ' ');
        std::cout << "\n";
    }
}

void BlackBoard::addShape(const std::shared_ptr<Shape>& shape) {
    shapes.emplace_back(shape);
    shape->draw(boardGrid);
}

void BlackBoard::listShapes() const {
    for (const auto& shape : shapes)
        shape->printInfo();
}
