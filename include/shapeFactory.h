#pragma once
#include "shape.h"
#include <map>


class ShapeFactory {
private:
    std::map<std::string, std::regex> shapesParameters;

    std::string validateShape(const std::string& args);
    std::vector<int> validateParameters(const std::string& shape, const std::string& parametersStr);
public:
    ShapeFactory() = default;
    ShapeFactory(int boardWidth, int boardLength);

    std::shared_ptr<Shape> createShape(const std::string& args);
};
