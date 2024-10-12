#include "../include/line.h"


Line::Line(bool filled, const std::string& color, std::vector<int> params)
    : Rectangle(filled, color, { params[0], params[1], params[2] == 0 ? params[3] : 0, params[2] == 0 ? 0 : params[3] }) {
    Line::validateParameters({ params[2] });
}

void Line::validateParameters(const std::vector<int> &parameters) {
    if (parameters[0] != 0 && parameters[0] != 90)
        throw std::invalid_argument("Only horizontal 0º and vertical 90º lines are supported.");
}

std::string Line::toString() {
    return getType() + ' ' + vertice.toString() + " " + std::to_string(width != 0 ? 0 : 90) + " " + std::to_string(width != 0 ? width : length);
}

std::string Line::getType() const {
    return "line";
}
