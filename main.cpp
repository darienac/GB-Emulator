#include <iostream>

#define SDL_MAIN_HANDLED

#include "view/GUIWindow.h"

int main() {
    std::cout << "Hello, World!" << std::endl;
    GUIWindow window("Hello World");

    unsigned char** bitmap = window.getScreen()->getBitmap();
    for (int r = 0; r < GUIWindow::RENDER_HEIGHT; r++) {
        for (int c = 0; c < GUIWindow::RENDER_WIDTH; c++) {
            bitmap[r][c] = (r+c) % 4;
        }
    }

    IControls* controls = window.getControls();

    window.render();
    while (true) {
        window.pollEvents();
        std::cout << controls->B() << std::endl;
    }
    return 0;
}
