#include "../include/application.h"
#include "../include/circle.h"
#include "../include/rectangle.h"
#include "../include/triangle.h"

int main() {
    BlackBoard board;
    board.addShape(std::make_shared<Triangle>(5, 1, 1));
    board.show();

//    Application app;
//    app.run();

    return 0;
}