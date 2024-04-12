//
// Created by dacma on 3/21/2024.
//

#include "GlobalFlags.h"

bool GlobalFlags::debug = false;
bool GlobalFlags::manualdbg = true; // sets if emulator should wait for user input between instructions
bool GlobalFlags::showRegisters = true;

bool GlobalFlags::checkForStuckInstruction = false; // sets if emulator should throw an error if an instruction doesn't increment the PC
bool GlobalFlags::showControls = false;
bool GlobalFlags::matchTranscript = false; // writes data to output.txt
bool GlobalFlags::printSerialOut = false; // writes serial data to stdout

uint16_t GlobalFlags::initialPC = 0x100; // Initial PC value, should be 0x100 for normal runs
unsigned int GlobalFlags::framesPerSecond = 60; // Normally set to 60