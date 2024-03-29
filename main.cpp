#include <iostream>

#define SDL_MAIN_HANDLED

#include "view/GUIWindow.h"
#include "controller/Emulator.h"
#include "GlobalFlags.h"

int main() {
    GUIWindow window("GB Emulator");

    unsigned char** bitmap = window.getScreen()->getBitmap();
    for (int r = 0; r < GUIWindow::RENDER_HEIGHT; r++) {
        for (int c = 0; c < GUIWindow::RENDER_WIDTH; c++) {
//            bitmap[r][c] = (r+c) % 4;
            bitmap[r][c] = 0;
        }
    }

    IControls* controls = window.getControls();

//    std::string romPath = "./roms/01-special.gb";
    std::string romPath = "./roms/02-interrupts.gb";
//    std::string romPath = "./roms/11-op a,(hl).gb";
//    std::string romPath = "./roms/tetris.gb";
    Emulator emulator(window.getScreen(), controls, romPath);
    while (true) {
        emulator.runFrame();
        window.pollEvents();
        if (GlobalFlags::showControls) {
            bitmap[0][1] = controls->up() ? 3 : 1;
            bitmap[1][0] = controls->left() ? 3 : 1;
            bitmap[1][2] = controls->right() ? 3 : 1;
            bitmap[2][1] = controls->down() ? 3 : 1;
            bitmap[1][5] = controls->select() ? 3 : 1;
            bitmap[1][7] = controls->start() ? 3 : 1;
            bitmap[1][10] = controls->B() ? 3 : 1;
            bitmap[1][12] = controls->A() ? 3 : 1;
        }
        window.render();
        SDL_Delay(15);
    }

    return 0;
}
