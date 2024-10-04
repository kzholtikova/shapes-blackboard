#pragma once
#include "shape.h"


class Triangle : public Shape {
private:
    int height;
public:
    Triangle(int x, int y, int triangleHeight) : Shape(x, y), height(triangleHeight) { };

    void draw() override;
};
