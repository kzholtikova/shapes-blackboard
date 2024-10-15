#pragma once
#include "command.h"
#include <map>

using grid = std::vector<std::vector<std::vector<std::weak_ptr<Shape>>>>;

class Application {
private:
    static std::map<std::string, Command*> commands;
    BlackBoard board = BlackBoard(165, 10);
public:
    void run();

    static std::string readCommand(const std::string& input);
    static std::vector<std::string> readArguments(const std::string& input);
};
