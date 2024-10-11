#include "../include/shape.h"

int Shape::lastId = -1;

void Shape::resetLastID() {
    lastId = -1;
}

int Shape::getId() const {
    return id;
}

std::string Shape::getColor() const {
    return color;
}
