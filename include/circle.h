#pragma once
#include"shape.h"


class Circle : Shape {
private:
    Point center;
    int radius;
public:
    Circle(const Point& circleCenter, int circleRadius);
    static std::unique_ptr<Shape> create(const std::string& args);

    void draw() override;
};
