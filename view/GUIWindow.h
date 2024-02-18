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
    static const int WINDOW_SCALE;

    SDL_Window* window;
    SDL_Renderer* renderer;
    SDL_Texture* texture;

    unsigned char* bitmapBuffer;
    unsigned char** bitmap;
public:
    static const int RENDER_WIDTH;
    static const int RENDER_HEIGHT;

    GUIWindow(const std::string& name);
    void pollEvents();
    void render();

    unsigned char** getBitmap();

    ~GUIWindow();
};


#endif //GAMEBOY_EMULATOR_GUIWINDOW_H
