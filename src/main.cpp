#include "app.h"

int main() {
    try {
        const auto engine = new Engine();
        engine->run();
        delete engine;
        return EXIT_SUCCESS;
    } catch (const std::exception &e) {
        std::cout << "Exception: " << e.what() << std::endl;
        return EXIT_FAILURE;
    }
}