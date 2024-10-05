#pragma once
#include <iostream>
#include <regex>


struct Point {
    int x;
    int y;

    Point(int x, int y) : x(x), y(y) { };
};

class Shape : public std::enable_shared_from_this<Shape> {
protected:
    static int lastId;
    int id;
    Point vertice;

    using grid = std::vector<std::vector<std::vector<std::weak_ptr<Shape>>>>;
    Shape(int x, int y) : vertice(x, y), id(++lastId) { }
public:
    virtual ~Shape() = default;
    virtual void draw(grid& grid) = 0;
};
