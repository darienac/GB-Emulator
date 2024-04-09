//
// Created by dacma on 2/22/2024.
//

#include "Controls.h"

const int Controls::JOYSTICK_DEADZONE = 4915;
const bool Controls::INVERT_AB = false;

void Controls::setControl(char mask, bool value) {
    buttonStates = value ? (buttonStates | mask) : (buttonStates & ~mask);
}



void Controls::handleKey(SDL_Keycode sym, bool pressed) {
    switch(sym) {
        case SDLK_w:
        case SDLK_UP:
            setControl(b_up, pressed);

            if (pressed) {
                setControl(b_down, false);
            }
            break;
        case SDLK_s:
        case SDLK_DOWN:
            setControl(b_down, pressed);
            if (pressed) {
                setControl(b_up, false);
            }
            break;
        case SDLK_a:
        case SDLK_LEFT:
            setControl(b_left, pressed);
            if (pressed) {
                setControl(b_right, false);
            }
            break;
        case SDLK_d:
        case SDLK_RIGHT:
            setControl(b_right, pressed);
            if (pressed) {
                setControl(b_left, false);
            }
            break;
        case SDLK_RETURN:
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

void Controls::handleJoystick() {
    Sint32 x = SDL_GameControllerGetAxis(controller, SDL_CONTROLLER_AXIS_LEFTX);
    Sint32 y = SDL_GameControllerGetAxis(controller, SDL_CONTROLLER_AXIS_LEFTY);
    if (x * x + y * y < JOYSTICK_DEADZONE * JOYSTICK_DEADZONE) {
        setControl(b_up, false);
        setControl(b_down, false);
        setControl(b_left, false);
        setControl(b_right, false);
        return;
    }
    setControl(b_up, y < x / 2 && y < x / -2);
    setControl(b_down, y > x / 2 && y > x / -2);
    setControl(b_left, x < y / 2 && x < y / -2);
    setControl(b_right, x > y / 2 && x > y / -2);
}

void Controls::handleControllerButton(SDL_GameControllerButton button, bool pressed) {
    switch(button) {
        case SDL_CONTROLLER_BUTTON_DPAD_UP:
            setControl(b_up, pressed);
            if (pressed) {
                setControl(b_down, false);
            }
            break;
        case SDL_CONTROLLER_BUTTON_DPAD_DOWN:
            setControl(b_down, pressed);
            if (pressed) {
                setControl(b_up, false);
            }
            break;
        case SDL_CONTROLLER_BUTTON_DPAD_LEFT:
            setControl(b_left, pressed);
            if (pressed) {
                setControl(b_right, false);
            }
            break;
        case SDL_CONTROLLER_BUTTON_DPAD_RIGHT:
            setControl(b_right, pressed);
            if (pressed) {
                setControl(b_left, false);
            }
            break;
        case SDL_CONTROLLER_BUTTON_START:
            setControl(b_start, pressed);
            break;
        case SDL_CONTROLLER_BUTTON_BACK:
            setControl(b_select, pressed);
            break;
        case SDL_CONTROLLER_BUTTON_A:
        case SDL_CONTROLLER_BUTTON_Y:
            setControl(INVERT_AB ? b_B : b_A, pressed);
            break;
        case SDL_CONTROLLER_BUTTON_B:
        case SDL_CONTROLLER_BUTTON_X:
            setControl(INVERT_AB ? b_A : b_B, pressed);
            break;
    }
}

Controls::Controls() {
    buttonStates = 0;

    SDL_JoystickEventState(SDL_ENABLE);
    controller = SDL_GameControllerOpen(0);
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
        case SDL_CONTROLLERAXISMOTION:
            if (event.caxis.which != SDL_GameControllerGetPlayerIndex(controller) || (event.caxis.axis != SDL_CONTROLLER_AXIS_LEFTX && event.caxis.axis != SDL_CONTROLLER_AXIS_LEFTY)) {
                break;
            }
            handleJoystick();
            break;
        case SDL_CONTROLLERBUTTONDOWN:
        case SDL_CONTROLLERBUTTONUP:
            handleControllerButton((SDL_GameControllerButton) event.cbutton.button, event.type == SDL_CONTROLLERBUTTONDOWN);
    }
}

Controls::~Controls() {
    SDL_GameControllerClose(controller);
}

void Controls::setGamepad(char mask, bool value) {
    switch(mask){
        case b_up:
//            Gamepad::get_state()->up = value;
            break;
        case b_down:
//            Gamepad::get_state()->down = value;
            break;
        case b_left:
//            Gamepad::get_state()->left = value;
            break;
        case b_right:
//            Gamepad::get_state()->right = value;
            break;
        case b_A:
//            Gamepad::get_state()->a = value;
            break;
        case b_B:
//            Gamepad::get_state()->b = value;
            break;
        case b_select:
//            Gamepad::get_state()->select = value;
            break;
        case b_start:
//            Gamepad::get_state()->start = value;
            break;
        default:
            break;
    }
}

