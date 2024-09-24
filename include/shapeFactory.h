#pragma once
#include "shape.h"
#include <map>


class ShapeFactory {
private:
    using shapeBuilder = std::unique_ptr<Shape> (*)(const std::string&);
    static std::map<std::string, shapeBuilder> shapeBuilders;
public:
    static std::unique_ptr<Shape> build(const std::string& shape, const std::string& args);
};
