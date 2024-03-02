//
// Created by Tyson Peterson on 2/14/24.
//

#include <map>
#include "Cartridge.h"

static const char *ROM_TYPES[] = {
        "ROM ONLY",
        "MBC1",
        "MBC1+RAM",
        "MBC1+RAM+BATTERY",
        "0x04 ???",
        "MBC2",
        "MBC2+BATTERY",
        "0x07 ???",
        "ROM+RAM 1",
        "ROM+RAM+BATTERY 1",
        "0x0A ???",
        "MMM01",
        "MMM01+RAM",
        "MMM01+RAM+BATTERY",
        "0x0E ???",
        "MBC3+TIMER+BATTERY",
        "MBC3+TIMER+RAM+BATTERY 2",
        "MBC3",
        "MBC3+RAM 2",
        "MBC3+RAM+BATTERY 2",
        "0x14 ???",
        "0x15 ???",
        "0x16 ???",
        "0x17 ???",
        "0x18 ???",
        "MBC5",
        "MBC5+RAM",
        "MBC5+RAM+BATTERY",
        "MBC5+RUMBLE",
        "MBC5+RUMBLE+RAM",
        "MBC5+RUMBLE+RAM+BATTERY",
        "0x1F ???",
        "MBC6",
        "0x21 ???",
        "MBC7+SENSOR+RUMBLE+RAM+BATTERY",
};

//static const char *LIC_CODE[0xA5] = {
//        [0x00] = "None",
//        [0x01] = "Nintendo R&D1",
//        [0x08] = "Capcom",
//        [0x13] = "Electronic Arts",
//        [0x18] = "Hudson Soft",
//        [0x19] = "b-ai",
//        [0x20] = "kss",
//        [0x22] = "pow",
//        [0x24] = "PCM Complete",
//        [0x25] = "san-x",
//        [0x28] = "Kemco Japan",
//        [0x29] = "seta",
//        [0x30] = "Viacom",
//        [0x31] = "Nintendo",
//        [0x32] = "Bandai",
//        [0x33] = "Ocean/Acclaim",
//        [0x34] = "Konami",
//        [0x35] = "Hector",
//        [0x37] = "Taito",
//        [0x38] = "Hudson",
//        [0x39] = "Banpresto",
//        [0x41] = "Ubi Soft",
//        [0x42] = "Atlus",
//        [0x44] = "Malibu",
//        [0x46] = "angel",
//        [0x47] = "Bullet-Proof",
//        [0x49] = "irem",
//        [0x50] = "Absolute",
//        [0x51] = "Acclaim",
//        [0x52] = "Activision",
//        [0x53] = "American sammy",
//        [0x54] = "Konami",
//        [0x55] = "Hi tech entertainment",
//        [0x56] = "LJN",
//        [0x57] = "Matchbox",
//        [0x58] = "Mattel",
//        [0x59] = "Milton Bradley",
//        [0x60] = "Titus",
//        [0x61] = "Virgin",
//        [0x64] = "LucasArts",
//        [0x67] = "Ocean",
//        [0x69] = "Electronic Arts",
//        [0x70] = "Infogrames",
//        [0x71] = "Interplay",
//        [0x72] = "Broderbund",
//        [0x73] = "sculptured",
//        [0x75] = "sci",
//        [0x78] = "THQ",
//        [0x79] = "Accolade",
//        [0x80] = "misawa",
//        [0x83] = "lozc",
//        [0x86] = "Tokuma Shoten Intermedia",
//        [0x87] = "Tsukuda Original",
//        [0x91] = "Chunsoft",
//        [0x92] = "Video system",
//        [0x93] = "Ocean/Acclaim",
//        [0x95] = "Varie",
//        [0x96] = "Yonezawa/s’pal",
//        [0x97] = "Kaneko",
//        [0x99] = "Pack in soft",
//        [0xA4] = "Konami (Yu-Gi-Oh!)"
//};

static const std::map<char, std::string> LIC_CODE = {
        {0x00, "None",},
        {0x01, "Nintendo R&D1",},
        {0x08, "Capcom",},
        {0x13, "Electronic Arts",},
        {0x18, "Hudson Soft",},
        {0x19, "b-ai",},
        {0x20, "kss",},
        {0x22, "pow",},
        {0x24, "PCM Complete",},
        {0x25, "san-x",},
        {0x28, "Kemco Japan",},
        {0x29, "seta",},
        {0x30, "Viacom",},
        {0x31, "Nintendo",},
        {0x32, "Bandai",},
        {0x33, "Ocean/Acclaim",},
        {0x34, "Konami",},
        {0x35, "Hector",},
        {0x37, "Taito",},
        {0x38, "Hudson",},
        {0x39, "Banpresto",},
        {0x41, "Ubi Soft",},
        {0x42, "Atlus",},
        {0x44, "Malibu",},
        {0x46, "angel",},
        {0x47, "Bullet-Proof",},
        {0x49, "irem",},
        {0x50, "Absolute",},
        {0x51, "Acclaim",},
        {0x52, "Activision",},
        {0x53, "American sammy",},
        {0x54, "Konami",},
        {0x55, "Hi tech entertainment",},
        {0x56, "LJN",},
        {0x57, "Matchbox",},
        {0x58, "Mattel",},
        {0x59, "Milton Bradley",},
        {0x60, "Titus",},
        {0x61, "Virgin",},
        {0x64, "LucasArts",},
        {0x67, "Ocean",},
        {0x69, "Electronic Arts",},
        {0x70, "Infogrames",},
        {0x71, "Interplay",},
        {0x72, "Broderbund",},
        {0x73, "sculptured",},
        {0x75, "sci",},
        {0x78, "THQ",},
        {0x79, "Accolade",},
        {0x80, "misawa",},
        {0x83, "lozc",},
        {0x86, "Tokuma Shoten Intermedia",},
        {0x87, "Tsukuda Original",},
        {0x91, "Chunsoft",},
        {0x92, "Video system",},
        {0x93, "Ocean/Acclaim",},
        {0x95, "Varie",},
        {0x96, "Yonezawa/s’pal",},
        {0x97, "Kaneko",},
        {0x99, "Pack in soft",},
        {0xA4, "Konami (Yu-Gi-Oh!)"}
};


Cartridge::Cartridge(std::string fileName) {
    ifstream inputFile(fileName);

    if (!inputFile.is_open()) {
        cout << "Error opening ROM" << endl;
        exit(-1);
    }

    inputFile.seekg(0, std::ios::end);
    streampos fileSize = inputFile.tellg();
    inputFile.seekg(0, std::ios::beg);

    cartSize = static_cast<int>(fileSize);

    cartData = new char[cartSize];
    inputFile.read(cartData, cartSize);

    char* name = cartData + 0x134;
    name[16] = 0;
    romTitle = string(name);

    romType = ROM_TYPES[cartData[0x147]];
    licensee = LIC_CODE.at(cartData[0x145]);

    romSize = 32 << cartData[0x148];
}

void Cartridge::printHeaderInfo() {
    cout << "ROM Title: " << romTitle << endl;
    cout << "Licensee: " << licensee << endl;
    cout << "ROM Type: " << romType << endl;
    cout << "ROM Size: " << romSize << " KiB" << endl;
}

uint8_t Cartridge::read(uint16_t addr) {
    return cartData[addr];
}

void Cartridge::write(uint16_t addr, uint8_t byte) {
    //TODO
}