#pragma once
#include"shape.h"


class Circle : Shape {
private:
    Point center;
    int radius;
public:
    Circle(const Point& circleCenter, int circleRadius);

    void draw() override;
};
