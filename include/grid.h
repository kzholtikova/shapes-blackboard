#pragma once
#include "shapeFactory.h"


class Grid {
private:
    std::vector<std::vector<std::vector<std::weak_ptr<Shape>>>> grid;
public:
    Grid(int width, int length) : grid(length, std::vector<std::vector<std::weak_ptr<Shape>>>(width)) { };
    std::weak_ptr<Shape> getFrontShapeAt(int x, int y, const std::shared_ptr<Shape>& selected);

    void show(const std::shared_ptr<Shape>& selected);
    void addShapePoints(const std::shared_ptr<Shape>& shapePtr);
};
