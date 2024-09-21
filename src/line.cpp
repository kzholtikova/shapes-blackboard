#include "../include/line.h"


Line::Line(const Point& startPoint, int lineLength, int angle) {
    if (angle == 0 || angle == 90)
        orientation = static_cast<Orientation>(angle);
    else
        throw std::invalid_argument("Invalid line angle: " + std::to_string(angle));

    start = startPoint;
    length = lineLength;
}

void Line::draw() {

}
