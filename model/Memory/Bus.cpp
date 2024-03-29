//
// Created by Tyson Peterson on 2/26/24.
//

#include "Bus.h"
#include "DMA.h"

uint8_t Bus::read(uint16_t address) {
    if (address < 0x8000) {
        //ROM Data
        return cart->read(address);
    } else if (address < 0xA000) {
        //Char/Map Data
        return vRam->read(address);
    } else if (address < 0xC000) {
        //Cartridge RAM
        return cart->read(address);
    } else if (address < 0xE000) {
        //WRAM (Working RAM)
        return wRam->read(address);
    } else if (address < 0xFE00) {
        //reserved echo ram...
        return 0;
    } else if (address < 0xFEA0) {
        //OAM
        if (dma->transferring()) {
            return 0xFF;
        }

        return oamRam->read(address);
    } else if (address < 0xFF00) {
        //reserved unusable...
        return 0;
    } else if (address < 0xFF80) {
        //IO Registers... TODO
        //return io_read(address);
        if (address == 0xFF0F) {
            return interruptFlag;
        }
    } else if (address == 0xFFFF) {
        //CPU ENABLE REGISTER...
        return interruptEnable;
    }

    //NO_IMPL
    return hRam->read(address);
}

void Bus::write(uint16_t address, uint8_t value) {
    if (address < 0x8000) {
        //ROM Data
        cart->write(address, value);
    } else if (address < 0xA000) {
        //Char/Map Data
        vRam->write(address, value);
    } else if (address < 0xC000) {
        //EXT-RAM
        cart->write(address, value);
    } else if (address < 0xE000) {
        //WRAM
        wRam->write(address, value);
    } else if (address < 0xFE00) {
        //reserved echo ram
    } else if (address < 0xFEA0) {
        //OAM
        if (dma->transferring()) {
            return;
        }

        oamRam->write(address, value);
    } else if (address < 0xFF00) {
        //unusable reserved
    } else if (address < 0xFF80) {
        //IO Registers... TODO
        //io_write(address, value);
        if (address == 0xFF0F) {
            interruptFlag = value;
        }
    } else if (address == 0xFFFF) {
        //CPU SET ENABLE REGISTER
        interruptEnable = value;
    } else {
        hRam->write(address, value);
    }
}