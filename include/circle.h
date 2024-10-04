#pragma once
#include"shape.h"


class Circle : public Shape {
private:
    int radius;
public:
    Circle(int x, int y, int circleRadius) : Shape(x, y), radius(circleRadius) { };

    void draw() override;
};
