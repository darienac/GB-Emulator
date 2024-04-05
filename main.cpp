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
//    std::string romPath = "./roms/02-interrupts.gb";
//    std::string romPath = "./roms/03-op sp,hl.gb";
//    std::string romPath = "./roms/04-op r,imm.gb";
//    std::string romPath = "./roms/05-op rp.gb";
//    std::string romPath = "./roms/06-ld r,r.gb";
//    std::string romPath = "./roms/07-jr,jp,call,ret,rst.gb";
//    std::string romPath = "./roms/08-misc instrs.gb";
//    std::string romPath = "./roms/09-op r,r.gb";
//    std::string romPath = "./roms/10-bit ops.gb";
//    std::string romPath = "./roms/11-op a,(hl).gb";
    std::string romPath = "./roms/dr_mario.gb";
//    std::string romPath = "./roms/000-write_to_x8000.gb";
//    std::string romPath = "./roms/flood_vram.gb";
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
