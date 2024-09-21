#pragma once
#include "shape.h"


class Triangle : Shape {
private:
    Point vertice;
    int height;
public:
    Triangle(const Point& verticePoint, int triangleHeight);

    void draw() override;
};
