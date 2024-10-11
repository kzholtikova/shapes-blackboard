#pragma once
#include <sys/ioctl.h>
#include <unistd.h>
#include "shapeFactory.h"


class BlackBoard {
public:
    static std::map<std::string, std::string> colors;

    BlackBoard(int width, int length);

    bool isEmpty() const;
    void draw();
    void clear();

    void addShape(const std::shared_ptr<Shape>& shape);
    void removeLastShape();
    bool isUniqueShape(const std::shared_ptr<Shape>& newShape);
    void listShapes() const;
    void saveShapes(std::fstream& file) const;
private:
    using grid = std::vector<std::vector<std::vector<std::weak_ptr<Shape>>>>;
    grid boardGrid;
    std::vector<std::shared_ptr<Shape>> shapes;
};

