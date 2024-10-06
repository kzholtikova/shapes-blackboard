#pragma once
#include "shape.h"
#include <map>


class ShapeFactory {
private:
    static std::vector<std::string> shapes;
    int maxX, maxY;

    void validateShape(const std::string& shape);
    int isNumber(const std::string& arg);
    int isNumberInRange(const std::string& arg, int from, int to);
    int isNumberInRange(const std::string& arg, std::vector<int> values);
public:
    ShapeFactory(int boardWidth, int boardLength) : maxX(boardWidth), maxY(boardLength) { };

    std::shared_ptr<Shape> createShape(const std::string& args);
};
