#include "../include/shape.h"


int Shape::getId() const {
    return id;
}

std::string Shape::getColor() const {
    return color;
}

void Shape::paint(const std::string& newColor) {
    color = newColor;
}

std::string Shape::getStyle() const {
    return filled ? "filled" : "frame";
}

std::string Shape::toString() {
    return getType() + " " + getStyle() + " " + getColor() + " " + vertice.toString() + " ";
}
