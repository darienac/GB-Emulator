//
// Created by dacma on 3/21/2024.
//

#include "GlobalFlags.h"

const bool GlobalFlags::debug = false;
const bool GlobalFlags::manualdbg = true; // sets if emulator should wait for user input between instructions
const bool GlobalFlags::showRegisters = true;

const bool GlobalFlags::checkForStuckInstruction = false; // sets if emulator should throw an error if an instruction doesn't increment the PC
const bool GlobalFlags::showControls = false;
const bool GlobalFlags::matchTranscript = false; // writes data to output.txt
const bool GlobalFlags::printSerialOut = false; // writes serial data to stdout