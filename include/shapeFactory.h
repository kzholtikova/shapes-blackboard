#pragma once
#include "shape.h"
#include <map>


class ShapeFactory {
private:
    static int lastId;
public:
    static std::map<std::string, std::string> colors;
    static std::map<std::string, std::function<std::shared_ptr<Shape>(int, bool, std::string, const std::vector<int>&)>> shapeConstructors;

    template <typename ShapeType>
    static std::shared_ptr<Shape> createShape(int id, bool filled, const std::string& color, const std::vector<int>& params);
    static std::shared_ptr<Shape> createValidShape(const std::vector<std::string>& args, int id = ++lastId);

    static void resetLastId();
    static std::string getValidShapeType(const std::string& shape);
    static std::vector<int> getValidParameters(const std::vector<std::string>& strParams);
    static bool isFilled(const std::string& style);
    static std::string getValidColor(const std::string& color);
    static void validateNumberOfArguments(const std::vector<std::string>& args, int num, bool required = true);
};
