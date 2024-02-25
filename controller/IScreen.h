//
// Created by dacma on 2/22/2024.
//

#ifndef GAMEBOY_EMULATOR_ISCREEN_H
#define GAMEBOY_EMULATOR_ISCREEN_H

class IScreen {
public:
    virtual unsigned char** getBitmap() = 0; // Returns 2D array of pixels of Gameboy pixels to read/modify. The ordering is row-major, so you would use getBitmap()[row][column] or getBitmap()[y][x] to get a specific pixel. Only use values 0-3 for the 4 grayscale values the Gameboy supports
    virtual void enableScreen() = 0;
    virtual void disableScreen() = 0;
    // Add more virtual methods you would like to be implemented

    virtual ~IScreen() = default;
};

#endif //GAMEBOY_EMULATOR_ISCREEN_H
