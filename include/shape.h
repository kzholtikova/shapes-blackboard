#pragma once
#include <iostream>
#include <regex>


struct Point {
    int x;
    int y;

    Point(int x, int y) : x(x), y(y) { };
    std::string toString() const;
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
    int getId() const;

    virtual void draw(grid& grid) = 0;
    virtual std::string toString() = 0;
};
