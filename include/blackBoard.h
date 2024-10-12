#pragma once
#include <sys/ioctl.h>
#include <unistd.h>
#include "grid.h"


class BlackBoard {
public:
    BlackBoard(int width, int length);

    std::unique_ptr<Grid> getGrid() const;
    std::weak_ptr<Shape> getSelectedShape() const;
    bool isEmpty() const;
    void clear();

    void addShape(const std::shared_ptr<Shape>& shape);
    void replaceSelectedShape(const std::shared_ptr<Shape>& shape);
    void removeLastShape();
    bool isUniqueShape(const std::shared_ptr<Shape>& newShape);
    void listShapes() const;
    void saveShapes(std::fstream& file) const;
private:
    Grid boardGrid;
    std::vector<std::shared_ptr<Shape>> shapes;
    std::weak_ptr<Shape> selectedShape;

    int  findShapeIndex(int id);
};

