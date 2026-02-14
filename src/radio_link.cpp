#include "radio_link.hpp"
#include <iostream>
#include <iomanip>
#include <random>
#include <algorithm>

static std::vector<uint8_t> last_packet;

void RadioLink::send(const std::vector<uint8_t>& data)
{
    last_packet = data;

    std::cout << "[RADIO TX] ";
    for (uint8_t b : data) {
        std::cout << std::hex
                  << std::setw(2)
                  << std::setfill('0')
                  << static_cast<int>(b)
                  << " ";
    }
    std::cout << std::dec << std::endl;
}

std::vector<uint8_t> RadioLink::receive()
{
    return last_packet;
}
