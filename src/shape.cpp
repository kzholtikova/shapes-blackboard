#include "../include/shape.h"

int Shape::lastId = -1;

int Shape::getId() const {
    return id;
}

std::string Point::toString() const {
    return std::to_string(x) + " " + std::to_string(y);
}
