//
// Created by dacma on 2/22/2024.
//

#include "BitmapScreen.h"

BitmapScreen::BitmapScreen(unsigned char **bitmap) {
    this->bitmap = bitmap;
}

unsigned char **BitmapScreen::getBitmap() {
    return bitmap;
}

void BitmapScreen::enableScreen() {
    // Might implement this to blank the screen later
}

void BitmapScreen::disableScreen() {

}
