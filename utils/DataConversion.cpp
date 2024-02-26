#include <sstream>
#include <iomanip>
#include <iostream>

using namespace std;

/// @brief Conversions for debugging and testing
namespace DataTypeConversions
{
    /// @brief Convert a uint8_t to a hex string
    /// @param value The value to convert
    /// @return The hex string
    string UInt8ToHexString(uint8_t value)
    {
        stringstream stream;
        stream << "0x" << hex << setw(2) << setfill('0') << (int)value;
        return stream.str();
    }

    /// @brief Convert a uint16_t to a hex string
    /// @param value The value to convert
    /// @return The hex string
    string UInt16ToHexString(uint16_t value)
    {
        stringstream stream;
        stream << "0x" << hex << setw(4) << setfill('0') << (int)value;
        return stream.str();
    }
}