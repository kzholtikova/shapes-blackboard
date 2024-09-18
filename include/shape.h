#pragma once


struct Point {
    int x;
    int y;
};

class Shape {
protected:
    Point center;
public:
    virtual void draw() = 0;
};
