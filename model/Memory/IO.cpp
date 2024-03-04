//
// Created by BYU Rental on 3/1/2024.
//

#include "IO.h"

uint8_t IO::io_read(uint16_t address) {
    if(address == 0xFF00){
        return gamepad->get_output();
    }

    if (address == 0xFF01) {
        //return serial_data[0];
    }

    if (address == 0xFF02) {
        //return serial_data[1];
    }

    if (0xFF04 <= address && address <= 0xFF07) {
        //return timer_read(address);
    }

    if (address == 0xFF0F) {
        //return cpu_get_int_flags();
    }

    if (0xFF10 <= address && address <= 0xFF3F) {
        //ignore sound
        return 0;
    }

    if (0xFF40 <= address && address <= 0xFF4B) {
        //return lcd_read(address);
    }
}

void IO::io_write(uint16_t address, uint8_t value) {
    if(address == 0xFF00){
        //gamepad->get_output();
    }

    if (address == 0xFF01) {

    }

    if (address == 0xFF02) {

    }

    if (0xFF04 <= address && address <= 0xFF07) {

    }

    if (address == 0xFF0F) {

    }

    if (0xFF10 <= address && address <= 0xFF3F) {

    }

    if (0xFF40 <= address && address <= 0xFF4B) {

    }
}
