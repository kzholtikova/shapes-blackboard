#pragma once
#include <sys/ioctl.h>
#include <unistd.h>
#include "shapeFactory.h"


class BlackBoard {
private:
    ShapeFactory shapeFactory;

    std::vector<std::vector<int>> grid;  // stores counters of shapes including the point
    std::vector<std::unique_ptr<Shape>> shapes;
    int drawnCounter = 0;
    // when show(): counter < shapes.Count -> draw from shapes[last]
    // when undo(): counter < shapes.Count -> delete from list; counter = shapes.Count -> delete + undraw
public:
    BlackBoard();
    ShapeFactory* getShapeFactory();

    void addShape(Shape* shape);
    void show();
    void undo();
};

