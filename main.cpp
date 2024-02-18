#include <iostream>

#define SDL_MAIN_HANDLED

#include "view/GUIWindow.h"

int main() {
    std::cout << "Hello, World!" << std::endl;
    GUIWindow window("Hello World");

    while (true) {
        window.pollEvents();
    }
    return 0;
}
