#pragma once
#include <sys/ioctl.h>
#include <unistd.h>
#include "shapeFactory.h"


class BlackBoard {
public:
    BlackBoard();

    ShapeFactory* getShapeFactory() const;
    int getWidth() const;
    int getLength() const;

    void addShape(const std::shared_ptr<Shape> shape);
    void show() const;
    void undo();
private:
    using grid = std::vector<std::vector<std::vector<std::weak_ptr<Shape>>>>;
    grid boardGrid;  // stores counters of shapes including the point
    std::vector<std::shared_ptr<Shape>> shapes;
    std::unique_ptr<ShapeFactory> shapeFactory;
    int width, length;

    int drawnCounter = 0;
    // when show(): counter < shapes.Count -> draw from shapes[last]
    // when undo(): counter < shapes.Count -> delete from list; counter = shapes.Count -> delete + undraw

};

