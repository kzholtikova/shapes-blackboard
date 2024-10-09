#pragma once
#include <iostream>
#include "blackBoard.h"


class Command {
public:
    virtual ~Command() = default;
    virtual void execute(const std::vector<std::string>& args, BlackBoard& board) = 0;
};

class HelpCommand : public Command {
public:
    void execute(const std::vector<std::string>& args, BlackBoard& board) override;
};

class DrawCommand : public Command {
public:
    void execute(const std::vector<std::string>& args, BlackBoard& board) override;
};

class ListCommand : public Command {
public:
    void execute(const std::vector<std::string>& args, BlackBoard& board) override;
};

class ShapesCommand : public Command {
public:
    void execute(const std::vector<std::string>& args, BlackBoard& board) override;
};

class AddCommand : public Command {
public:
    void execute(const std::vector<std::string>& args, BlackBoard& board) override;
};

class UndoCommand : public Command {
public:
    void execute(const std::vector<std::string>& args, BlackBoard& board) override;
};

class ClearCommand : public Command {
public:
    void execute(const std::vector<std::string>& args, BlackBoard& board) override;
};

class SaveCommand : public Command {
public:
    void execute(const std::vector<std::string>& args, BlackBoard& board) override;
};

class LoadCommand : public Command {
public:
    void execute(const std::vector<std::string>& args, BlackBoard& board) override;
};
