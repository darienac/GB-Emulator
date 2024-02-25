//
// Created by dacma on 2/22/2024.
//

#ifndef GAMEBOY_EMULATOR_BITMAPSCREEN_H
#define GAMEBOY_EMULATOR_BITMAPSCREEN_H


#include "../controller/IScreen.h"

class BitmapScreen : public IScreen {
private:
    unsigned char** bitmap;
public:
    explicit BitmapScreen(unsigned char** bitmap);

    unsigned char** getBitmap() override;
    void enableScreen() override;
    void disableScreen() override;

    ~BitmapScreen() override;
};


#endif //GAMEBOY_EMULATOR_BITMAPSCREEN_H
