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
              << "add [shape] [filled/frame] [color] [x] [y] [parameters]\n"
              << "select [id/coordinates]\n"
              << "edit: changes selected shape parameters\n"
              << "move: changes selected shape vertice coordinates\n"
              << "paint: changes selected shape color\n"
              << "remove: removes selected shape\n"
              << "clear: removes all shapes\n"
              << "save [filepath]: saves blackboard to the file\n"
              << "load [filepath]: loads blackboard from the file\n"
              << "exit: ends the program\n";
}

void DrawCommand::execute(const std::vector<std::string>& args, BlackBoard& board) {
    Command::execute(args, board);
    board.getGrid()->show(board.getSelectedShape().lock());
}

void ListCommand::execute(const std::vector<std::string>& args, BlackBoard& board) {
    Command::execute(args, board);
    board.listShapes();
}

void ShapesCommand::execute(const std::vector<std::string>& args, BlackBoard& board) {
    Command::execute(args, board);
    std::cout << "circle filled/frame white/red/green/blue/yellow/magenta x y radius\n"
              << "triangle filled/frame white/red/green/blue/yellow/magenta x y height\n"
              << "rectangle filled/frame white/red/green/blue/yellow/magenta x y width length\n"
              << "line filled/frame white/red/green/blue/yellow/magenta x y angle(0/ 90) length\n";
}

void AddCommand::execute(const std::vector<std::string>& args, BlackBoard &board) {
    auto shape = ShapeFactory::createValidShape(args);
    if (!board.isUniqueShape(shape))
        throw std::invalid_argument(args[0] + " already exists.");
    board.addShape(shape);
}

void RemoveCommand::execute(const std::vector<std::string>& args, BlackBoard& board) {
    Command::execute(args, board);
    if (board.isEmpty())
        throw std::invalid_argument("Nothing to undo!");

    board.removeSelectedShape();
}

void ClearCommand::execute(const std::vector<std::string>& args, BlackBoard& board) {
    Command::execute(args, board);
    board.clear();
    ShapeFactory::resetLastId();
}

void SaveCommand::execute(const std::vector<std::string>& args, BlackBoard& board) {
    ShapeFactory::validateNumberOfArguments(args, 1);

    FileHandle fileHandle(args[0], std::ios::out);
    board.saveShapes(fileHandle.getStream());
}

void LoadCommand::execute(const std::vector<std::string>& args, BlackBoard& board) {
    ShapeFactory::validateNumberOfArguments(args, 1);

    FileHandle fileHandle(args[0], std::ios::in);
    auto& file = fileHandle.getStream();

    ClearCommand().execute({}, board);

    std::string line;
    while (std::getline(file, line))
        AddCommand().execute(Application::readArguments(line), board);
}

void EditCommand::execute(const std::vector<std::string> &args, BlackBoard &board) {
    auto selectedShape = board.getSelectedShape().lock();
    std::vector<std::string> fullArgs = Application::readArguments(board.getSelectedShape().lock()->toString());
    fullArgs.insert(fullArgs.begin() + 5, args.begin(), args.end());
    auto newShape = ShapeFactory::createValidShape(fullArgs, board.getSelectedShape().lock()->getId());

    board.replaceSelectedShape(newShape);
}

void MoveCommand::execute(const std::vector<std::string>& args, BlackBoard& board) {
    ShapeFactory::validateNumberOfArguments(args, 2);
    std::vector<std::string> fullArgs = Application::readArguments(board.getSelectedShape().lock()->toString());
    fullArgs[3] = args[0];
    fullArgs[4] = args[1];
    auto newShape= ShapeFactory::createValidShape(fullArgs, board.getSelectedShape().lock()->getId());

    board.replaceSelectedShape(newShape);
}

void PaintCommand::execute(const std::vector<std::string> &args, BlackBoard &board) {
    ShapeFactory::validateNumberOfArguments(args, 1);
    if (board.isEmpty())
        throw std::invalid_argument("No selected shape!");

    std::string color = ShapeFactory::getValidColor(args[0]);
    board.getSelectedShape().lock()->paint(color);
}

void SelectCommand::execute(const std::vector<std::string> &args, BlackBoard &board) {
    auto params = ShapeFactory::getValidParameters(args);
    if (params.size() == 1)
        board.selectShapeByID(params[0]);
    else if (params.size() == 2)
        board.selectShapeByCoordinates(params[0], params[1]);
    else
        throw std::invalid_argument("Invalid arguments.");
}
