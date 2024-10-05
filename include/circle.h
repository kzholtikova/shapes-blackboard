#pragma once
#include"shape.h"


class Circle : public Shape {  // center as a vertice
private:
    int radius;
public:
    Circle(int x, int y, int circleRadius) : Shape(x, y), radius(circleRadius) { };

    void draw(grid& grid) override;
    void printInfo() override;
};
