//
// Created by Tyson Peterson on 2/14/24.
//
#include <string>
#include <cstdint>
#include <fstream>
#include <iostream>

#ifndef GAMEBOY_EMULATOR_CARTRIDGE_H
#define GAMEBOY_EMULATOR_CARTRIDGE_H

using namespace std;

class Cartridge {
private:
    char* cartData;
    int cartSize;

    /*
     * Basic Cartridge info... Needed only to
     * confirm ROM is being read
     */
    string romTitle;
    string romType;
    string licensee;
    int romSize;
public:
    /*
     * Pass in relative file path,
     * loads the byte data into cartData
     */
    Cartridge(string fileName);

    /*
     * Prints simple debugging info
     */
    void printHeaderInfo();

    /*
     * Takes a 2 byte address (offset)
     * and writes the passed in byte to cartData
     * We probably won't use this until we test
     * cartridges with MEM banks or RAM.
     */
    void write(uint16_t addr, uint8_t byte);

    /*
     * Takes a 2 byte address (offset)
     * and reads the associated byte from cartData
     */
    uint8_t read(uint16_t addr);
};


#endif //GAMEBOY_EMULATOR_CARTRIDGE_H
