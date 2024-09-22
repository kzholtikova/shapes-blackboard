#pragma once
#include "shape.h"


class BlackBoard {
private:
    std::vector<std::vector<int>> grid;  // stores counters of shapes including the point
    std::vector<Shape> shapes;
    int drawnCounter = 0;
    // when show(): counter < shapes.Count -> draw from shapes[last]
    // when undo(): counter < shapes.Count -> delete from list; counter = shapes.Count -> delete + undraw
public:
    BlackBoard();
    void show();
};

