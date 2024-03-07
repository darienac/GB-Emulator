//
// Created by BYU Rental on 3/1/2024.
//

#ifndef GAMEBOY_EMULATOR_GAMEPAD_H
#define GAMEBOY_EMULATOR_GAMEPAD_H

#include <cstdint>

class Gamepad{

private:
    struct gamepad_state {
        bool start;
        bool select;
        bool a;
        bool b;
        bool up;
        bool down;
        bool left;
        bool right;

        explicit gamepad_state(bool val) : start(val), select(val), a(val), b(val),
                                           up(val), down(val), left(val), right(val) {}
    };
    bool button_selected{};
    bool direction_selected{};
    static gamepad_state state;


public:

    static gamepad_state *get_state();
    Gamepad(){
        state = gamepad_state(false);
    }



public:
    [[nodiscard]] uint8_t get_output() const;
    void set_sel(uint8_t value);
};


#endif //GAMEBOY_EMULATOR_GAMEPAD_H
