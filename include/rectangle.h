#pragma once
#include "shape.h"


class Rectangle : public Shape {  // Left top as a vertice
protected:
    int width;
    int length;
public:
    Rectangle(int id, bool filled, const std::string& color, std::vector<int> parameters);
    std::string getType() const override;
    std::vector<Point> getPoints() const override;

    void validateParameters(const std::vector<int>& parameters) override;
    std::string toString() override;
};
