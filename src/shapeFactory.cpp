#include <sstream>
#include "../include/shapeFactory.h"
#include "../include/blackBoard.h"
#include "../include/circle.h"
#include "../include/triangle.h"
#include "../include/line.h"


std::map<std::string, std::function<std::shared_ptr<Shape>(bool, std::string, const std::vector<int>&)>> ShapeFactory::shapeConstructors = {
        {"circle", ShapeFactory::createShape<Circle>},
        {"line", ShapeFactory::createShape<Line>},
        {"rectangle", ShapeFactory::createShape<Rectangle>},
        {"triangle", ShapeFactory::createShape<Triangle>},
};

template<typename ShapeType>
std::shared_ptr<Shape> ShapeFactory::createShape(bool filled, const std::string& color,  const std::vector<int> &params) {
    return std::make_shared<ShapeType>(filled, color, params);
}

std::string ShapeFactory::getValidShapeType(const std::string& shape) {
    if (shapeConstructors.count(shape) == 0)
        throw std::invalid_argument("Invalid shape.");
    return shape;
}

std::vector<int> ShapeFactory::getValidParameters(const std::vector<std::string> &strParams) {
    std::vector<int> params;
    for (auto param : strParams) {
        if (param.empty() || !std::all_of(param.begin(), param.end(), ::isdigit))
            throw std::invalid_argument("Parameters must be numeric.");
        params.emplace_back(std::stoi(param));
    }

    return params;
}

bool ShapeFactory::isFilled(const std::string &style) {
    if (style == "filled")
        return true;
    else if (style == "frame")
        return false;

    throw std::invalid_argument("Invalid shape style.");
}

std::string ShapeFactory::getValidColor(const std::string& color) {
    if (BlackBoard::colors.count(color) == 0)
        throw std::invalid_argument("Invalid color! Please choose from white, red, green, blue, yellow, magenta.");
    return color;
}
