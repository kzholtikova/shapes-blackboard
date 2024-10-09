#include "../include/line.h"


Line::Line(bool filled, std::string color, std::vector<int> params)
    : Rectangle(filled, color, { params[0], params[1], params[2] == 0 ? params[3] : 0, params[2] == 0 ? 0 : params[3] }) {
    if (params[2] != 0 && params[2] != 90)
        throw std::invalid_argument("Only horizontal 0º and vertical 90º lines are supported.");

    // !!!!
}
