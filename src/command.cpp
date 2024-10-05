#include "../include/command.h"
#include <filesystem>

void Command::execute(const std::string& args, BlackBoard &board) {
    if (!args.empty())
        throw std::invalid_argument("Excessive arguments.");
}

void DrawCommand::execute(const std::string& args, BlackBoard& board) {
    Command::execute(args, board);
}

void ListCommand::execute(const std::string& args, BlackBoard& board) {
    Command::execute(args, board);
}

void ShapesCommand::execute(const std::string& args, BlackBoard& board) {
    Command::execute(args, board);
}

void AddCommand::execute(const std::string& args, BlackBoard &board) {
    board.addShape(board.getShapeFactory()->createShape(args));
}

void UndoCommand::execute(const std::string& args, BlackBoard& board) {
    Command::execute(args, board);
}

void ClearCommand::execute(const std::string& args, BlackBoard& board) {
    Command::execute(args, board);
}

void FileCommand::execute(const std::string& args, BlackBoard &board) {
    if (args.size() != 1)
        throw std::invalid_argument("Invalid number of arguments.");
}

void SaveCommand::execute(const std::string& args, BlackBoard& board) {
    FileCommand::execute(args, board);
}

void LoadCommand::execute(const std::string& args, BlackBoard& board) {
    FileCommand::execute(args, board);
    if (!std::filesystem::exists(args))
        throw std::invalid_argument("The file at " + args + " doesn't exist");
}
