//
// Created by dacma on 2/17/2024.
//

#include <iostream>
#include "GUIWindow.h"

const int GUIWindow::RENDER_FLAGS = SDL_RENDERER_ACCELERATED;
const int GUIWindow::WINDOW_FLAGS = 0;
const int GUIWindow::RENDER_WIDTH = 160;
const int GUIWindow::RENDER_HEIGHT = 144;
const int GUIWindow::WINDOW_SCALE = 5;

GUIWindow::GUIWindow(const std::string& name) {
    int renderFlags = SDL_RENDERER_ACCELERATED;
    int windowFlags = 0;
    if (SDL_Init(SDL_INIT_EVERYTHING) < 0) {
        throw ("Unable to initialize SDL: " + std::string(SDL_GetError()));
    }

    window = SDL_CreateWindow(name.c_str(), SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, RENDER_WIDTH*WINDOW_SCALE, RENDER_HEIGHT*WINDOW_SCALE, WINDOW_FLAGS);
    if (!window) {
        throw ("Failed to create window: " + std::string(SDL_GetError()));
    }

    SDL_SetHint(SDL_HINT_RENDER_SCALE_QUALITY, "nearest");
    renderer = SDL_CreateRenderer(window, -1, RENDER_FLAGS);
    if (!renderer) {
        throw ("Failed to create renderer: " + std::string(SDL_GetError()));
    }

    bitmapBuffer = new unsigned char[RENDER_WIDTH * RENDER_HEIGHT];
    bitmap = new unsigned char*[RENDER_HEIGHT];
    for (int i = 0; i < RENDER_HEIGHT; i++) {
        bitmap[i] = bitmapBuffer + RENDER_WIDTH * i;
    }

    texture = SDL_CreateTexture(renderer, SDL_PIXELFORMAT_RGB24, SDL_TEXTUREACCESS_STREAMING, RENDER_WIDTH, RENDER_HEIGHT);
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
    unsigned char* pixels;
    int pitch;
    SDL_LockTexture(texture, nullptr, (void**) &pixels, &pitch);

    // Do stuff
    for (int r = 0; r < RENDER_HEIGHT; r++) {
        for (int c = 0; c < RENDER_WIDTH; c++) {
            switch (bitmap[r][c]) {
                case 3:
                    pixels[0] = 155;
                    pixels[1] = 188;
                    pixels[2] = 15;
                    break;
                case 2:
                    pixels[0] = 118;
                    pixels[1] = 145;
                    pixels[2] = 13;
                    break;
                case 1:
                    pixels[0] = 48;
                    pixels[1] = 98;
                    pixels[2] = 48;
                    break;
                case 0:
                    pixels[0] = 15;
                    pixels[1] = 56;
                    pixels[2] = 15;
                    break;
                default:
                    pixels[0] = bitmap[r][c];
                    pixels[1] = bitmap[r][c];
                    pixels[2] = bitmap[r][c];
            }
            pixels += 3;
        }
    }

    SDL_UnlockTexture(texture);

//    SDL_SetRenderDrawColor(renderer, 96, 128, 255, 255);
//    SDL_RenderClear(renderer);
    SDL_RenderCopy(renderer, texture, nullptr, nullptr);

    SDL_RenderPresent(renderer);
}

unsigned char **GUIWindow::getBitmap() {
    return bitmap;
}

GUIWindow::~GUIWindow() {
    SDL_DestroyTexture(texture);
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);

    delete[] bitmapBuffer;
    delete[] bitmap;
}