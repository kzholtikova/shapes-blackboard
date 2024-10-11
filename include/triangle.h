#pragma once
#include "shape.h"



class Triangle : public Shape {  // top point as a vertice
private:
    int height;
public:
    Triangle(bool filled, const std::string& color, std::vector<int> parameters);

    void draw(grid& grid) override;
    std::string toString() override;
};
