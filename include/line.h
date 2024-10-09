#pragma once
#include "rectangle.h"


class Line : public Rectangle {  // left end as a vertice
public:
    Line(bool filled, std::string color, std::vector<int> parameters);
    std::string toString() override;
};
