#include "crc8.hpp"

uint8_t crc8(const std::vector<uint8_t>& data)
{
    uint8_t crc = 0x00;

    for (uint8_t byte : data) {
        crc ^= byte;
        for (int i = 0; i < 8; ++i) {
            if (crc & 0x80)
                crc = (crc << 1) ^ 0x07;
            else
                crc <<= 1;
        }
    }

    return crc;
}
