#pragma once
#include "shape.h"


class Triangle : Shape {
private:
    Point vertice;
    int height;
public:
    Triangle(const Point& verticePoint, int triangleHeight);
    static std::unique_ptr<Shape> create(const std::string& args);

    void draw() override;
};
