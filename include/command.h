#pragma once
#include <iostream>
#include "blackBoard.h"


class Command {
public:
    virtual ~Command() = default;
    virtual void execute(const std::string& args, BlackBoard& board) = 0;
};

class DrawCommand : public Command {
public:
    void execute(const std::string& args, BlackBoard& board) override;
};

class ListCommand : public Command {
public:
    void execute(const std::string& args, BlackBoard& board) override;
};

class ShapesCommand : public Command {
public:
    void execute(const std::string& args, BlackBoard& board) override;
};

class AddCommand : public Command {
public:
    void execute(const std::string& args, BlackBoard& board) override;
};

class UndoCommand : public Command {
public:
    void execute(const std::string& args, BlackBoard& board) override;
};

class ClearCommand : public Command {
public:
    void execute(const std::string& args, BlackBoard& board) override;
};

class FileCommand: public Command {
public:
    void execute(const std::string& args, BlackBoard& board) override;
};

class SaveCommand : public FileCommand {
public:
    void execute(const std::string& args, BlackBoard& board) override;
};

class LoadCommand : public FileCommand {
public:
    void execute(const std::string& args, BlackBoard& board) override;
};
