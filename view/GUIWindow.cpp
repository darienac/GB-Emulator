//
// Created by dacma on 2/17/2024.
//

#include <iostream>
#include "GUIWindow.h"

const int GUIWindow::RENDER_FLAGS = SDL_RENDERER_ACCELERATED;
const int GUIWindow::WINDOW_FLAGS = 0;
const int GUIWindow::RENDER_WIDTH = 160;
const int GUIWindow::RENDER_HEIGHT = 144;

GUIWindow::GUIWindow(const std::string& name) {
    int renderFlags = SDL_RENDERER_ACCELERATED;
    int windowFlags = 0;
    if (SDL_Init(SDL_INIT_EVERYTHING) < 0) {
        throw ("Unable to initialize SDL: " + std::string(SDL_GetError()));
    }

    window = SDL_CreateWindow(name.c_str(), SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, RENDER_WIDTH, RENDER_HEIGHT, WINDOW_FLAGS);
    if (!window) {
        throw ("Failed to create window: " + std::string(SDL_GetError()));
    }

    SDL_SetHint(SDL_HINT_RENDER_SCALE_QUALITY, "nearest");
    renderer = SDL_CreateRenderer(window, -1, RENDER_FLAGS);
    if (!renderer) {
        throw ("Failed to create renderer: " + std::string(SDL_GetError()));
    }

    bitmapBuffer = new char[RENDER_WIDTH * RENDER_HEIGHT];
    bitmap = new char*[RENDER_HEIGHT];
    for (int i = 0; i < RENDER_HEIGHT; i++) {
        bitmap[i] = bitmapBuffer + RENDER_WIDTH * i;
    }
}

void GUIWindow::pollEvents() {
    SDL_Event event;
    while (SDL_PollEvent(&event)) {
        switch (event.type) {
            case SDL_QUIT:
                exit(0);
            default:
                break;
        }
    }
}

void GUIWindow::render() {
    SDL_SetRenderDrawColor(renderer, 96, 128, 255, 255);
    SDL_RenderClear(renderer);

    SDL_RenderPresent(renderer);
}

char **GUIWindow::getBitmap() {
    return bitmap;
}

GUIWindow::~GUIWindow() {
    SDL_DestroyTexture(texture);
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);

    delete[] bitmapBuffer;
    delete[] bitmap;
}