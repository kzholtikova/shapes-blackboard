#pragma once
#include <iostream>
#include <regex>

struct Point {
    int x;
    int y;

    Point(int x, int y) : x(x), y(y) { };
};

class Shape {
protected:
    Point vertice;

    Shape(int x, int y) : vertice(x, y) { }
public:
    virtual ~Shape() = default;
    virtual void draw() = 0;
};
