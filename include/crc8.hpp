#ifndef CRC8_HPP
#define CRC8_HPP

#include <cstdint>
#include <vector>

/*
 * CRC-8 (polynomial 0x07)
 * Used for packet integrity in embedded systems
 */
uint8_t crc8(const std::vector<uint8_t>& data);

#endif // CRC8_HPP
