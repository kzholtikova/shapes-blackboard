#pragma once
#include "shape.h"
#include <map>


class ShapeFactory {
public:
    static std::map<std::string, std::string> colors;
    static std::map<std::string, std::function<std::shared_ptr<Shape>(bool, std::string, const std::vector<int>&)>> shapeConstructors;

    template <typename ShapeType>
    static std::shared_ptr<Shape> createShape(bool, const std::string&, const std::vector<int>& params);
    static std::shared_ptr<Shape> createValidShape(const std::vector<std::string>& args);

    static std::string getValidShapeType(const std::string& shape);
    static std::vector<int> getValidParameters(const std::vector<std::string>& strParams);
    static bool isFilled(const std::string& style);
    static std::string getValidColor(const std::string& color);
    static void validateNumberOfArguments(const std::vector<std::string>& args, int required);
};
