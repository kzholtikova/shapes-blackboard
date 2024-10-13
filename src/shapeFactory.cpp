#include <sstream>
#include "../include/shapeFactory.h"
#include "../include/circle.h"
#include "../include/triangle.h"
#include "../include/line.h"


int ShapeFactory::lastId = -1;
std::map<std::string, std::string> ShapeFactory::colors = {
        {"white", "37"},
        {"red", "31"},
        {"green", "32"},
        {"yellow", "33"},
        {"blue", "34"},
        {"magenta", "35"},
};

void ShapeFactory::resetLastId() {
    lastId = -1;
}

std::map<std::string, std::function<std::shared_ptr<Shape>(int, bool, std::string, const std::vector<int>&)>> ShapeFactory::shapeConstructors = {
        {"circle", ShapeFactory::createShape<Circle>},
        {"line", ShapeFactory::createShape<Line>},
        {"rectangle", ShapeFactory::createShape<Rectangle>},
        {"triangle", ShapeFactory::createShape<Triangle>},
};

template<typename ShapeType>
std::shared_ptr<Shape> ShapeFactory::createShape(int id, bool filled, const std::string& color,  const std::vector<int> &params) {
    return std::make_shared<ShapeType>(id, filled, color, params);
}

std::shared_ptr<Shape> ShapeFactory::createValidShape(const std::vector<std::string>& args, int id) {
    validateNumberOfArguments(args, 6, false);
    std::vector<int> params = getValidParameters({args.begin() + 3, args.end()});
    return shapeConstructors[getValidShapeType(args[0])](id, isFilled(args[1]), getValidColor(args[2]), params);
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
    if (colors.count(color) == 0)
        throw std::invalid_argument("Invalid color! Please choose from white, red, green, blue, yellow, magenta.");
    return color;
}

void ShapeFactory::validateNumberOfArguments(const std::vector<std::string> &args, int num, bool required) {
    if (args.size() < num || (required && args.size() != num))
        throw std::invalid_argument("Invalid number of arguments.");
}
