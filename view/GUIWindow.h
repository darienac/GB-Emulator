//
// Created by dacma on 2/17/2024.
//

#ifndef GAMEBOY_EMULATOR_GUIWINDOW_H
#define GAMEBOY_EMULATOR_GUIWINDOW_H

#include <SDL2/SDL_main.h>
#include <SDL2/SDL.h>

class GUIWindow {
private:
    static const int RENDER_FLAGS;
    static const int WINDOW_FLAGS;
    static const int RENDER_WIDTH;
    static const int RENDER_HEIGHT;

    SDL_Renderer* renderer;
    SDL_Window* window;
    char* bitmapBuffer;
    char** bitmap;
public:
    GUIWindow(const std::string& name);
    void pollEvents();

    ~GUIWindow();
};


#endif //GAMEBOY_EMULATOR_GUIWINDOW_H
