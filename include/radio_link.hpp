#ifndef RADIO_LINK_HPP
#define RADIO_LINK_HPP

#include <vector>
#include <cstdint>

class RadioLink {
public:
    //may corrupt bytes for sim purposes
    void send(const std::vector<uint8_t>& data);

    // Simulated receive (loopback)
    std::vector<uint8_t> receive();
};

#endif // RADIO_LINK_HPP
