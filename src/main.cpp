#include "../include/application.h"

int main() {
    Application app;
    app.run();

    try {
        Application::getCommand(command)->execute(args);
    } catch (const std::invalid_argument& e) {
        std::cerr << "Error: " << e.what() << "\n";
        std::exit(EXIT_FAILURE);
    }

    return 0;
}