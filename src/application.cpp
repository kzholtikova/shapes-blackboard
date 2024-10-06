#include "../include/application.h"
#include <sstream>

std::map<std::string, Command*> Application::commands = {
    {"help", new HelpCommand},
    {"draw", new DrawCommand},
    {"list", new ListCommand},
    {"shapes", new ShapesCommand},
    {"add", new AddCommand},
    {"undo", new UndoCommand},
    {"clear", new ClearCommand},
    {"save", new SaveCommand},
    {"load", new LoadCommand},
};

void Application::run() {
    std::string input;
    std::cout << "Enter command (help/ exit): ";
    while (std::getline(std::cin, input) && input != "exit") {
        std::string cmd, args;
        try {
            readCommand(input, cmd, args);
            commands[cmd]->execute(args, board);
        } catch (std::invalid_argument& e){
            std::cout << "Error: " << e.what() << std::endl;
        }

        std::cout << "Enter command (help/ exit): ";
    }
}

void Application::readCommand(const std::string& input, std::string& cmd, std::string& args) {
    std::stringstream ss(input);
    ss >> cmd;
    if (commands.count(cmd) == 0)
        throw std::invalid_argument("No command named " + cmd + ".");

    std::getline(ss, args);
    if (!args.empty() && args[0] == ' ')
        args = args.substr(1);
}
