#include "../include/shapeFactory.h"

std::unique_ptr<Shape> ShapeFactory::build(const std::string &shape, const std::string& args) {
    return shapeBuilders[shape](args);
}
