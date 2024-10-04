#include "../include/blackBoard.h"


BlackBoard::BlackBoard() {
    struct winsize size;
    ioctl(STDOUT_FILENO, TIOCGWINSZ, &size);
    shapeFactory = ShapeFactory(size.ws_col, size.ws_row);
}

ShapeFactory* BlackBoard::getShapeFactory() {
    return &shapeFactory;
}

void BlackBoard::show() {
    for (auto& row : grid) {
        for (int c : row)
            std::cout << (c > 0 ? "*" : " ");
        std::cout << "\n";
    }
}

void BlackBoard::addShape(Shape* shape) {
    shapes.emplace_back(std::unique_ptr<Shape>(shape));
}


