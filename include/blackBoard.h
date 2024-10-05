#pragma once
#include <sys/ioctl.h>
#include <unistd.h>
#include "shapeFactory.h"


class BlackBoard {
public:
    BlackBoard();

    ShapeFactory* getShapeFactory() const;

    void addShape(const std::shared_ptr<Shape>& shape);
    void listShapes() const;
    void draw() const;
private:
    using grid = std::vector<std::vector<std::vector<std::weak_ptr<Shape>>>>;
    grid boardGrid;  // stores counters of shapes including the point
    std::vector<std::shared_ptr<Shape>> shapes;
    std::unique_ptr<ShapeFactory> shapeFactory;
    int width, length;
};

