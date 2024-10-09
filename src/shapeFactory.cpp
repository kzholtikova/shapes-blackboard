#include <sstream>
#include "../include/shapeFactory.h"
#include "../include/circle.h"
#include "../include/triangle.h"
#include "../include/line.h"


std::map<std::string, std::function<std::shared_ptr<Shape>(bool, std::string, const std::vector<int>&)>> shapeConstructors = {
        {"circle", ShapeFactory::createShape<Circle>},
        {"line", ShapeFactory::createShape<Line>},
        {"rectangle", ShapeFactory::createShape<Rectangle>},
        {"triangle", ShapeFactory::createShape<Triangle>},
};

template<typename ShapeType>
std::shared_ptr<Shape> ShapeFactory::createShape(bool filled, std::string color,  const std::vector<int> &params) {
    return std::make_shared<ShapeType>(filled, color, params);
}

std::string ShapeFactory::getValidShapeType(const std::string& shape) {
    if (shapeConstructors.count(shape) == 0)
        throw std::invalid_argument("Invalid shape.");
    return shape;
}

std::vector<int> ShapeFactory::getValidParameters(const std::vector<std::string> &strParams) {
    if (!std::all_of(strParams.begin(), strParams.end(), [](const std::string& str) {
        return !str.empty() && std::all_of(str.begin(), str.end(), ::isdigit);
    }))
        throw std::invalid_argument("");

    std::vector<int> params;
    std::transform(strParams.begin(), strParams.end(), params.begin(), [](const std::string& str) {
        return std::stoi(str);
    });

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
    return color;
}

//int ShapeFactory::isNumberInRange(const std::string& arg, int from, int to) {
//    int number = isNumber(arg);
//    if(number < from || number > to)
//        throw std::invalid_argument("Parameter " + arg + " should be in the range " +
//                                    std::to_string(from) + "-" + std::to_string(to) + ".");
//
//    return number;
//}
//
//int ShapeFactory::isNumberInRange(const std::string& arg, std::vector<int> values) {
//    int number = isNumber(arg);
//    if(std::find(values.begin(), values.end(), number) == values.end())
//        throw std::invalid_argument("Unsupported value near " + arg + ".");
//
//    return number;
//}
//
//int ShapeFactory::isNumber(const std::string& arg) {
//    if (arg.empty() || !std::all_of(arg.begin(), arg.end(), ::isdigit))
//        throw std::invalid_argument("Invalid argument near " + arg + ".");
//    return std::stoi(arg);
//}
