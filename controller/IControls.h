//
// Created by dacma on 2/22/2024.
//

#ifndef GAMEBOY_EMULATOR_ICONTROLS_H
#define GAMEBOY_EMULATOR_ICONTROLS_H

class IControls {
public:
    virtual bool up() = 0;
    virtual bool down() = 0;
    virtual bool left() = 0;
    virtual bool right() = 0;
    virtual bool start() = 0;
    virtual bool select() = 0;
    virtual bool A() = 0;
    virtual bool B() = 0;
    // All of these methods just return true/false if the button is being pressed on a keyboard or controller

    virtual ~IControls() = default;
};

#endif //GAMEBOY_EMULATOR_ICONTROLS_H
