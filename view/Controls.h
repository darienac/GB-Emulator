//
// Created by dacma on 2/22/2024.
//

#ifndef GAMEBOY_EMULATOR_CONTROLS_H
#define GAMEBOY_EMULATOR_CONTROLS_H


#include <SDL2/SDL.h>
#include "../controller/IControls.h"

class Controls : public IControls {
private:
    enum Buttons {
        b_up = 1,
        b_down = 2,
        b_left = 4,
        b_right = 8,
        b_start = 16,
        b_select = 32,
        b_A = 64,
        b_B = 128
    };

    static const int JOYSTICK_DEADZONE;
    static const bool INVERT_AB;

    char buttonStates;
    SDL_GameController* controller;

    void setControl(char mask, bool value);
    void handleKey(SDL_Keycode sym, bool pressed);
    void handleJoystick();
    void handleControllerButton(SDL_GameControllerButton button, bool pressed);
public:
    explicit Controls();

    void handleEvent(SDL_Event event);

    bool up() override;
    bool down() override;
    bool left() override;
    bool right() override;
    bool start() override;
    bool select() override;
    bool A() override;
    bool B() override;

    ~Controls() override;
};


#endif //GAMEBOY_EMULATOR_CONTROLS_H
