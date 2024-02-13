#include <iostream>

#define SDL_MAIN_HANDLED
#include <SDL2/SDL_main.h>
#include <SDL2/SDL.h>

int main() {
    std::cout << "Hello, World!" << std::endl;

    if (SDL_Init(SDL_INIT_EVERYTHING) != 0) {
        std::cout << "Unable to initialize SDL: " << SDL_GetError() << std::endl;
        return EXIT_FAILURE;
    }

    SDL_CreateWindow("GB Emulator", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 800, 600, 0);
    while (true) {}
    return 0;
}
