#include "../include/blackBoard.h"

void BlackBoard::show() {
    for (auto& row : grid) {
        for (int c : row)
            std::cout << (c > 0 ? "*" : " ");
        std::cout << "\n";
    }
}