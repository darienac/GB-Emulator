//
// Created by dacma on 2/22/2024.
//

#ifndef GAMEBOY_EMULATOR_CONTROLS_H
#define GAMEBOY_EMULATOR_CONTROLS_H


#include "../controller/IControls.h"

class Controls : public IControls {
private:
    char* buttonStates;
public:
    explicit Controls(char* buttonStates);

    bool up() override;
    bool down() override;
    bool left() override;
    bool right() override;
    bool start() override;
    bool select() override;
    bool A() override;
    bool B() override;
};


#endif //GAMEBOY_EMULATOR_CONTROLS_H
