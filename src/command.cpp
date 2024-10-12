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
              << "undo: removes the last added shape\n"
              << "clear: removes all shapes\n"
              << "save [filepath]: saves blackboard to the file\n"
              << "load [filepath]: loads blackboard from the file\n"
              << "exit: ends the program\n";
}

void DrawCommand::execute(const std::vector<std::string>& args, BlackBoard& board) {
    Command::execute(args, board);
    board.getGrid()->show();
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
    auto shape = ShapeFactory::createValidShape(args);
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
    Shape::resetLastID();
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
    std::vector<std::string> shapeProperties = { selectedShape->getType(), selectedShape->getStyle(), selectedShape->getColor() };
    shapeProperties.insert(shapeProperties.begin(), args.begin(), args.end());
    auto newShape = ShapeFactory::createValidShape(shapeProperties);
    
    board.replaceSelectedShape(newShape);
}

void MoveCommand::execute(const std::vector<std::string>& args, BlackBoard& board) {
    ShapeFactory::validateNumberOfArguments(args, 2);
    std::vector<std::string> fullArgs = Application::readArguments(board.getSelectedShape().lock()->toString());
    fullArgs[3] = args[0];
    fullArgs[4] = args[1];
    auto newShape = ShapeFactory::createValidShape(fullArgs);

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

}
