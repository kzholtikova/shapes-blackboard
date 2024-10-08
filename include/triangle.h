#pragma once
#include "shape.h"



class Triangle : public Shape {  // top point as a vertice
private:
    int height;
public:
    Triangle(int x, int y, int triangleHeight) : Shape(x, y), height(triangleHeight) { };

    void draw(grid& grid) override;
    std::string toString() override;
};
