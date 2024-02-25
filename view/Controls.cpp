//
// Created by dacma on 2/22/2024.
//

#include "Controls.h"

void Controls::setControl(char mask, bool value) {
    buttonStates = value ? (buttonStates | mask) : (buttonStates & ~mask);
}

void Controls::handleKey(SDL_Keycode sym, bool pressed) {
    switch(sym) {
        case SDLK_w:
        case SDLK_UP:
            setControl(b_up, pressed);
            break;
        case SDLK_s:
        case SDLK_DOWN:
            setControl(b_down, pressed);
            break;
        case SDLK_a:
        case SDLK_LEFT:
            setControl(b_left, pressed);
            break;
        case SDLK_d:
        case SDLK_RIGHT:
            setControl(b_right, pressed);
            break;
        case SDLK_KP_ENTER:
            setControl(b_start, pressed);
            break;
        case SDLK_RSHIFT:
            setControl(b_select, pressed);
            break;
        case SDLK_x:
        case SDLK_SPACE:
            setControl(b_A, pressed);
            break;
        case SDLK_z:
        case SDLK_LSHIFT:
            setControl(b_B, pressed);
            break;
        default:
            break;
    }
}

Controls::Controls() {
    buttonStates = 0;
}

bool Controls::up() {
    return buttonStates & b_up;
}

bool Controls::down() {
    return buttonStates & b_down;
}

bool Controls::left() {
    return buttonStates & b_left;
}

bool Controls::right() {
    return buttonStates & b_right;
}

bool Controls::start() {
    return buttonStates & b_start;
}

bool Controls::select() {
    return buttonStates & b_select;
}

bool Controls::A() {
    return buttonStates & b_A;
}

bool Controls::B() {
    return buttonStates & b_B;
}

void Controls::handleEvent(SDL_Event event) {
    switch (event.type) {
        case SDL_KEYDOWN:
        case SDL_KEYUP:
            handleKey(event.key.keysym.sym, event.type == SDL_KEYDOWN);
            break;
    }
}
