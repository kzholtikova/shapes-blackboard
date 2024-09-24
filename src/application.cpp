#include "../include/application.h"
#include "../include/circle.h"
#include "../include/line.h"
#include "../include/rectangle.h"
#include "../include/triangle.h"
#include <sstream>

std::map<std::string, Command*> Application::commands = {
    {"draw", new DrawCommand},
    {"list", new ListCommand},
    {"shapes", new ShapesCommand},
    {"add", new AddCommand},
    {"undo", new UndoCommand},
    {"clear", new ClearCommand},
    {"save", new SaveCommand},
    {"load", new LoadCommand},
};

std::map<std::string, Application::shapeBuilder> Application::shapeBuilders = {
    {"circle", &Circle::create},
    {"line", &Line::create},
    {"rectangle", &Rectangle::create},
    {"triangle", &Triangle::create}
};

void Application::run() {
    std::string input;
    std::cout << "Enter command (/ exit): ";
    while (std::getline(std::cin, input) && input != "exit") {
        std::string cmd, args;
        try {
            readCommand(input, cmd, args);
            commands[cmd]->execute(args, board);
        } catch (std::invalid_argument& e){
            std::cout << "Error: " << e.what() << std::endl;
        }

        std::cout << "Enter command (/ exit): ";
    }
}

void Application::readCommand(const std::string& input, std::string& cmd, std::string& args) {
    std::stringstream ss(input);
    ss >> cmd;
    if (commands.count(cmd) == 0)
        throw std::invalid_argument("No command named " + cmd);

    args = ss.str();
}
//
//std::string Application::readArguments(std::stringstream& ss) {
//    std::string args;
//    std::string arg;
//    while (ss >> arg)
//        args.push_back(arg);
//
//    return args;
//}
