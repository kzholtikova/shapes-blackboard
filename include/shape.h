#pragma once
#include <iostream>


struct Point {
    int x;
    int y;
};

class Shape {
protected:
    Point center;
public:
    virtual ~Shape() = default;
    virtual void draw() = 0;
};
