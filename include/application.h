#pragma once
#include "command.h"
#include <map>

using grid = std::vector<std::vector<std::vector<std::weak_ptr<Shape>>>>;

class Application {
private:
    static std::map<std::string, Command*> commands;
    BlackBoard board;

    static void readCommand(const std::string& input, std::string& cmd, std::string& args);
public:
    void run();
};
