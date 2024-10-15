#include "../include/application.h"
#include <sstream>

std::map<std::string, Command*> Application::commands = {
    {"help", new HelpCommand},
    {"draw", new DrawCommand},
    {"list", new ListCommand},
    {"shapes", new ShapesCommand},
    {"add", new AddCommand},
    {"remove", new RemoveCommand},
    {"clear", new ClearCommand},
    {"save", new SaveCommand},
    {"load", new LoadCommand},
    {"edit", new EditCommand},
    {"move", new MoveCommand},
    {"paint", new PaintCommand},
    {"select", new SelectCommand},
};

void Application::run() {
    std::string input;
    std::cout << "Enter command (help/ exit): ";
    while (std::getline(std::cin, input) && input != "exit") {
        try {
            auto cmd = readCommand(input);
            commands[cmd]->execute(readArguments(input.substr(cmd.size())), board);
        } catch (std::invalid_argument& e){
            std::cout << "Error: " << e.what() << std::endl;
        }

        std::cout << "Enter command (help/ exit): ";
    }
}

std::string Application::readCommand(const std::string& input) {
    std::stringstream ss(input);
    std::string cmd;
    ss >> cmd;

    if (commands.count(cmd) == 0)
        throw std::invalid_argument("No command named `" + cmd + "`.");
    return cmd;
}

std::vector<std::string> Application::readArguments(const std::string& input) {
    std::stringstream ss(input);
    std::string arg;
    std::vector<std::string> args;
    while (ss >> arg)
        args.emplace_back(arg);

    return args;
}
