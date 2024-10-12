#pragma once
#include "shapeFactory.h"


class Grid {
private:
    std::vector<std::vector<std::vector<std::weak_ptr<Shape>>>> grid;
public:
    Grid(int width, int length) : grid(length, std::vector<std::vector<std::weak_ptr<Shape>>>(width)) { };

    void show();
    void addShapePoints(const std::shared_ptr<Shape>& shapePtr);
    void removeShapePoints(const std::shared_ptr<Shape>& shape);
};
