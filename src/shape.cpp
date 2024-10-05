#include "../include/shape.h"

int Shape::lastId = -1;

std::string Point::toString() const {
    return "(" + std::to_string(x) + "; " + std::to_string(y) + ")";
}
