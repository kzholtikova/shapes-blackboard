#pragma once
#include "shape.h"


class Line : Shape {
public:
    Line(const Point& startPoint, int lineLength, int angle);
    static std::unique_ptr<Shape> create(const std::string& args);

    void draw() override;

    enum Orientation { Vertical=90, Horizontal=0 };
private:
    Point start;
    int length;
    Orientation orientation;
};
