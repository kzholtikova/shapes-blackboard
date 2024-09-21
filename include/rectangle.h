#pragma once
#include "shape.h"


class Rectangle : Shape {
private:
    Point center;
    int width;
    int length;
public:
    Rectangle(const Point& rectangleCenter, int rectangleWidth, int rectangleLength);

    void draw() override;
};
