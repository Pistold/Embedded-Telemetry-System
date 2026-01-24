#include "radio_link.hpp"
#include <iostream>
#include <iomanip>

void RadioLink::send(const std::vector<uint8_t>& data)
{
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
