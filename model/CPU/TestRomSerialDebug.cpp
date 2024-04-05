//
// Created by Tyson Peterson on 4/5/24.
//

#include "TestRomSerialDebug.h"

TestRomSerialDebug::TestRomSerialDebug() {
    message = "";
    messageOld = "";
}

void TestRomSerialDebug::update(Bus &bus) {
    if (bus.read(0xFF02) == 0x81 || bus.read(0xFF02) == 0x80) {  // 8 for high bit (availabe), 1 for low bit (master clock)
        message += bus.read(0xFF01);
        bus.write(0xFF02, 0);
    }
}

void TestRomSerialDebug::print() {
    if (messageOld != message) {
        std::cout << message << "\n";
        messageOld = message;
    }
}