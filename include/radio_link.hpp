#ifndef RADIO_LINK_HPP
#define RADIO_LINK_HPP

#include <vector>
#include <cstdint>

/*
 * Simulated radio / UART transport layer
 * Transport-agnostic and hardware-free
 */
class RadioLink {
public:
    void send(const std::vector<uint8_t>& data);
};

#endif // RADIO_LINK_HPP
