#include "../include/command.h"
#include "../include/fileHandle.h"
#include "../include/application.h"
#include <filesystem>


void Command::execute(const std::vector<std::string>& args, BlackBoard &board) {
    if (!args.empty())
        throw std::invalid_argument("Excessive arguments.");
}

void HelpCommand::execute(const std::vector<std::string> &args, BlackBoard &board) {
    Command::execute(args, board);
    std::cout << "draw: draws blackboard to the console\n"
              << "list: info about all added shapes\n"
              << "shapes: info about available shapes\n"
              << "add [shape] [x] [y] [parameters]\n"
              << "undo: removes the last added shape\n"
              << "clear: removes all shapes\n"
              << "save [filepath]: saves blackboard to the file\n"
              << "load [filepath]: loads blackboard from the file\n"
              << "exit: ends the program\n";
}

void DrawCommand::execute(const std::vector<std::string>& args, BlackBoard& board) {
    Command::execute(args, board);
    board.draw();
}

void ListCommand::execute(const std::vector<std::string>& args, BlackBoard& board) {
    Command::execute(args, board);
    board.listShapes();
}

void ShapesCommand::execute(const std::vector<std::string>& args, BlackBoard& board) {
    Command::execute(args, board);
    std::cout << "circle coordinates radius\n"
              << "triangle coordinates height\n"
              << "rectangle coordinates width length\n"
              << "line coordinates angle(0/ 90) length\n";
}

void AddCommand::execute(const std::vector<std::string>& args, BlackBoard &board) {
    if (args.size() < 6)
        throw std::invalid_argument("Insufficient arguments.");

    std::vector<int> params = ShapeFactory::getValidParameters({args.begin() + 3, args.end()});
    std::shared_ptr<Shape> shape = ShapeFactory::shapeConstructors[ShapeFactory::getValidShapeType(args[0])]
            (ShapeFactory::isFilled(args[1]), ShapeFactory::getValidColor(args[2]), params);

    if (!board.isUniqueShape(shape))
        throw std::invalid_argument(args[0] + " already exists.");

    board.addShape(shape);
}

void UndoCommand::execute(const std::vector<std::string>& args, BlackBoard& board) {
    Command::execute(args, board);
    if (board.isEmpty())
        throw std::invalid_argument("Nothing to undo!");

    board.removeLastShape();
}

void ClearCommand::execute(const std::vector<std::string>& args, BlackBoard& board) {
    Command::execute(args, board);
    board.clear();
}

void SaveCommand::execute(const std::vector<std::string>& args, BlackBoard& board) {
    if (args.size() != 1)
        throw std::invalid_argument("Invalid number of arguments.");

    FileHandle fileHandle(args[0], std::ios::out);
    board.saveShapes(fileHandle.getStream());
}

void LoadCommand::execute(const std::vector<std::string>& args, BlackBoard& board) {
    if (args.size() != 1)
        throw std::invalid_argument("Invalid number of arguments.");

    FileHandle fileHandle(args[0], std::ios::in);
    auto& file = fileHandle.getStream();

    board.clear();

    std::string line;
    while (std::getline(file, line))
        AddCommand().execute(Application::readArguments(line), board);
}
