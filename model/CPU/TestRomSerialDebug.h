//
// Created by Tyson Peterson on 4/5/24.
//

#ifndef GAMEBOY_EMULATOR_TESTROMSERIALDEBUG_H
#define GAMEBOY_EMULATOR_TESTROMSERIALDEBUG_H

#include <string>
#include "../Memory/Bus.h"
#include <iostream>

class TestRomSerialDebug {
private:
    std::string message;
    std::string messageOld;
public:
    TestRomSerialDebug();
    void update(Bus& bus);
    void print();
};


#endif //GAMEBOY_EMULATOR_TESTROMSERIALDEBUG_H
