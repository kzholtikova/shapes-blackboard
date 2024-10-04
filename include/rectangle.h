#pragma once
#include "shape.h"


class Rectangle : public Shape {
private:
    int width;
    int length;
public:
    Rectangle(int x, int y, int rectangleWidth, int rectangleLength) : Shape(x, y), width(rectangleWidth), length(rectangleLength) { };

    void draw() override;
};
