#pragma once
#include "command.h"
#include <map>


class Application {
private:
    static std::map<std::string, Command*> commands;
    BlackBoard board;

    static void readCommand(const std::string& input, std::string& cmd, std::string& args);
public:
    void run();
};
