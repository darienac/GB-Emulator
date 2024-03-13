cmake_minimum_required(VERSION 3.27)
project(gameboy_emulator)

find_package(SDL2 CONFIG REQUIRED)

set(CMAKE_CXX_STANDARD 23)

add_executable(gameboy_emulator main.cpp
        view/GUIWindow.cpp
        view/GUIWindow.h
        controller/IScreen.h
        controller/IControls.h
        view/BitmapScreen.cpp
        view/BitmapScreen.h
        view/Controls.cpp
        view/Controls.h
        model/CPU/CPU.cpp
        model/CPU/CPU.h
        model/CPU/Instruction.cpp
        model/CPU/Instruction.h
        model/PPU/PPU.cpp
        model/PPU/PPU.h
        model/Memory/DMA.cpp
        model/Memory/DMA.h
        model/Memory/Bus.cpp
        model/Memory/Bus.h
        model/Memory/OamRAM.cpp
        model/Memory/OamRAM.h
        model/Memory/VRAM.cpp
        model/Memory/VRAM.h
        model/Memory/Cartridge.cpp
        model/Memory/HRAM.cpp
        model/Memory/HRAM.h
        model/Memory/WRAM.cpp
        model/Memory/WRAM.h
        model/PPU/LCD.cpp
        model/PPU/LCD.h
        model/BitManip.cpp
        model/BitManip.h
        model/Memory/IO.cpp
        model/Memory/IO.h
        utils/DataConversion.cpp
        controller/Emulator.cpp
        controller/Emulator.h
        model/Structs.h
        model/IEmulator.h
)

target_compile_features(gameboy_emulator PRIVATE cxx_std_23)
target_link_libraries(gameboy_emulator PRIVATE SDL2::SDL2)
target_link_libraries(gameboy_emulator PRIVATE SDL2::SDL2main)