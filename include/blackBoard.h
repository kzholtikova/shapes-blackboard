#pragma once
#include <sys/ioctl.h>
#include <unistd.h>
#include "shapeFactory.h"


class BlackBoard {
public:
    BlackBoard(int width, int length);

    ShapeFactory* getShapeFactory() const;
    bool isEmpty() const;

    void addShape(const std::shared_ptr<Shape>& shape);
    void removeLastShape();
    bool isUniqueShape(const std::shared_ptr<Shape>& newShape);
    void listShapes() const;
    void saveShapes(std::fstream& file) const;
    void draw() const;
    void clear();
private:
    using grid = std::vector<std::vector<std::vector<std::weak_ptr<Shape>>>>;
    grid boardGrid;  // stores counters of shapes including the point
    std::vector<std::shared_ptr<Shape>> shapes;
    std::unique_ptr<ShapeFactory> shapeFactory;
};

