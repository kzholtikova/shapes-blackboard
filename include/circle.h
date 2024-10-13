#pragma once
#include"shape.h"


class Circle : public Shape {  // center as a vertice
private:
    int radius;
public:
    Circle(int id, bool filled, const std::string& color, std::vector<int> parameters);
    std::string getType() const override;
    std::vector<Point> getPoints() const override;

    void validateParameters(const std::vector<int>& parameters) override;
    std::string toString() override;
};
