#pragma once
#include"shape.h"


class Circle : public Shape {  // center as a vertice
private:
    int radius;
public:
    Circle(bool filled, std::string color, std::vector<int> parameters);

    void draw(grid& grid) override;
    std::string toString() override;
};
