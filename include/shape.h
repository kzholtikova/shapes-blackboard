#pragma once
#include "point.h"


class Shape : public std::enable_shared_from_this<Shape> {
protected:
    static int lastId;
    int id;
    Point vertice;
    bool filled;
    std::string color;

    using grid = std::vector<std::vector<std::vector<std::weak_ptr<Shape>>>>;
    explicit Shape(int x, int y, bool isFilled, const std::string& color) : vertice(Point(x, y)), filled(isFilled), color(color), id(++lastId) { }
public:
    virtual ~Shape() = default;
    static void resetLastID();
    int getId() const;
    virtual std::string getType() const = 0;
    std::string getStyle() const;
    std::string getColor() const;

    virtual std::vector<Point> getPoints() const = 0;
    void paint(const std::string& newColor);

    virtual void validateParameters(const std::vector<int>& parameters) = 0;
    virtual std::string toString() = 0;
};
