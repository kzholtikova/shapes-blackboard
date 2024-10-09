#pragma once
#include "shape.h"


class Rectangle : public Shape {  // Left top as a vertice
protected:
    int width;
    int length;
public:
    Rectangle(bool filled, std::string color, std::vector<int> parameters);

    void draw(grid& grid) override;
    std::string toString() override;
};
