#include "../include/application.h"
#include "../include/circle.h"
#include "../include/rectangle.h"
#include "../include/triangle.h"

int main() {
    BlackBoard board;
    board.addShape(std::make_shared<Circle>(150, 3, 5));
    board.addShape(std::make_shared<Triangle>(150, 3, 5));
    board.addShape(std::make_shared<Rectangle>(150, 3, 8, 4));
    board.show();

//    Application app;
//    app.run();

    return 0;
}