#include "../include/command.h"
#include "../include/fileHandle.h"
#include "../include/application.h"
#include <filesystem>


void Command::execute(const std::string& args, BlackBoard &board) {
    if (!args.empty())
        throw std::invalid_argument("Excessive arguments.");
}

void DrawCommand::execute(const std::string& args, BlackBoard& board) {
    Command::execute(args, board);
    Application::clearConsole();
    board.draw();
}

void ListCommand::execute(const std::string& args, BlackBoard& board) {
    Command::execute(args, board);
    board.listShapes();
}

void ShapesCommand::execute(const std::string& args, BlackBoard& board) {
    Command::execute(args, board);
    std::cout << "circle coordinates radius\n"
              << "triangle coordinates height\n"
              << "rectangle coordinates width length\n"
              << "line coordinates length angle(0/ 90)\n";
}

void AddCommand::execute(const std::string& args, BlackBoard &board) {
    board.addShape(board.getShapeFactory()->createShape(args));
}

void UndoCommand::execute(const std::string& args, BlackBoard& board) {
    Command::execute(args, board);
    if (board.isEmpty())
        throw std::invalid_argument("Nothing to undo!");
    board.removeLastShape();
}

void ClearCommand::execute(const std::string& args, BlackBoard& board) {
    Command::execute(args, board);
    board.clear();
}

void SaveCommand::execute(const std::string& args, BlackBoard& board) {
    FileHandle fileHandle(args, std::ios::out);
    board.saveShapes(fileHandle.getStream());
}

void LoadCommand::execute(const std::string& args, BlackBoard& board) {
    FileHandle fileHandle(args, std::ios::in);
    auto& file = fileHandle.getStream();

    std::string line;
    while (std::getline(file, line))
        AddCommand().execute(line, board);
}
