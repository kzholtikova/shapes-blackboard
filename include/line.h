#pragma once
#include "rectangle.h"


class Line : public Rectangle {  // left end as a vertice
public:
    Line(int id, bool filled, const std::string& color, std::vector<int> parameters);
    std::string getType() const override;

    void validateParameters(const std::vector<int>& parameters) override;
    std::string toString() override;
};
