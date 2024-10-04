#include <sstream>
#include "../include/shapeFactory.h"
#include "../include/circle.h"
#include "../include/line.h"
#include "../include/triangle.h"


ShapeFactory::ShapeFactory(int boardWidth, int boardLength) {
    std::string pointRegex = "^[1-" + std::to_string(boardWidth) + "] [1-" + std::to_string(boardLength) + "]";

    shapesParameters["circle"] = pointRegex + " [1-" + std::to_string(boardWidth / 2) + "]$";
    shapesParameters["line"] = pointRegex + " [1-9]+ [0|90]$";
    shapesParameters["rectangle"] = pointRegex + " " + pointRegex + "$";
    shapesParameters["triangle"] = pointRegex + " [1-" + std::to_string(boardLength) + "]$";
}

Shape* ShapeFactory::createShape(const std::string& args) {
    std::string shape = validateShape(args);
    std::vector<int> parameters = validateParameters(args.substr(shape.size()));

    if (shape == "circle")
        return new Circle(parameters[0], parameters[1], parameters[2]);
    if (shape == "line")
        return new Line(parameters[0], parameters[1], parameters[2], parameters[3]);
    if (shape == "rectangle")
        return new Rectangle(parameters[0], parameters[1], parameters[2], parameters[3]);
    if (shape == "triangle")
        return new Triangle(parameters[0], parameters[1], parameters[2]);
    return nullptr;
}


std::string ShapeFactory::validateShape(const std::string &args) {
    size_t firstSpace = args.find_first_of(' ');
    if (firstSpace == std::string::npos || firstSpace + 1 == args.size())
        throw std::invalid_argument("Invalid arguments.");

    std::string shape = args.substr(0, firstSpace);
    if (!shapesParameters.count(shape))
        throw std::invalid_argument("Invalid shape.");

    return shape;
}

std::vector<int> ShapeFactory::validateParameters(const std::string& shape, const std::string& parametersStr) {
    if (!std::regex_match(parametersStr, shapesParameters[shape]))
        throw std::invalid_argument("Invalid parameters for a " + shape + ".");

    std::istringstream iss(parametersStr);
    return { (std::istream_iterator<int>(iss)), std::istream_iterator<int>() };
}
