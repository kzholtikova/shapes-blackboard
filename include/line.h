#pragma once
#include "rectangle.h"


class Line : public Rectangle {
public:
    Line(int x, int y, int size, int angle) : Rectangle(x, y, angle == 0 ? size : angle, angle == 0 ? angle : size) { };

    void draw() override;
};
