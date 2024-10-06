#include <sstream>
#include "../include/shapeFactory.h"
#include "../include/circle.h"
#include "../include/rectangle.h"
#include "../include/triangle.h"


std::vector<std::string> ShapeFactory::shapes = { "circle", "triangle", "rectangle", "line" };

std::shared_ptr<Shape> ShapeFactory::createShape(const std::string& args) {
    std::stringstream ss(args);
    std::string shape, xStr, yStr, param, rest;
    ss >> shape >> xStr >> yStr >> param >> rest;

    validateShape(shape);
    int x = isNumberInRange(xStr, 0, maxX), y = isNumberInRange(yStr, 0, maxY);

    if (shape == "circle" && rest.empty())
        return  std::make_shared<Circle>(x, y,isNumberInRange(param, 2, maxY/2));
    if (shape == "line") {
        int angle = isNumberInRange(param, { 0, 90 });
        return std::make_shared<Line>(x, y, angle, isNumberInRange(rest, 1, angle == 0 ? maxX : maxY));
    }
    if (shape == "rectangle")
        return std::make_shared<Rectangle>(x, y, isNumberInRange(param, 1, maxX), isNumberInRange(rest, 1, maxY));
    if (shape == "triangle" && rest.empty())
        return std::make_shared<Triangle>(x, y, isNumberInRange(param, 1, maxY));

    throw std::invalid_argument("Invalid shape.");
}


void ShapeFactory::validateShape(const std::string& shape) {
    if (shape.empty())
        throw std::invalid_argument("Invalid arguments.");

    if (std::find(shapes.begin(), shapes.end(), shape) == shapes.end())
        throw std::invalid_argument("Invalid shape.");
}

int ShapeFactory::isNumberInRange(const std::string& arg, int from, int to) {
    int number = isNumber(arg);
    if(number < from || number > to)
        throw std::invalid_argument("Parameter " + arg + " should be in the range " +
                                    std::to_string(from) + "-" + std::to_string(to) + ".");

    return number;
}

int ShapeFactory::isNumberInRange(const std::string& arg, std::vector<int> values) {
    int number = isNumber(arg);
    if(std::find(values.begin(), values.end(), number) == values.end())
        throw std::invalid_argument("Unsupported value near " + arg + ".");

    return number;
}

int ShapeFactory::isNumber(const std::string& arg) {
    if (!std::all_of(arg.begin(), arg.end(), ::isdigit))
        throw std::invalid_argument("Invalid argument near " + arg + ".");
    return std::stoi(arg);
}
