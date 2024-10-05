#pragma once
#include "shape.h"


class Rectangle : public Shape {  // Left top as a vertice
protected:
    int width;
    int length;
public:
    Rectangle(int x, int y, int rectangleWidth, int rectangleLength) : Shape(x, y), width(rectangleWidth), length(rectangleLength) { };

    void draw(grid& grid) override;
    void printInfo() override;
};

class Line : public Rectangle {  // left end as a vertice
public:
    Line(int x, int y, int size, int angle) : Rectangle(x, y, angle == 0 ? size : angle, angle == 0 ? angle : size) { };
    void printInfo() override;
};
