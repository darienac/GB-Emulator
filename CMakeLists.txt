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
        view/Controls.h)

target_compile_features(gameboy_emulator PRIVATE cxx_std_23)
target_link_libraries(gameboy_emulator PRIVATE SDL2::SDL2)
target_link_libraries(gameboy_emulator PRIVATE SDL2::SDL2main)