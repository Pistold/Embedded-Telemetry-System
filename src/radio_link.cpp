#include "radio_link.hpp"
#include <iostream>
#include <iomanip>
#include <random>
#include <algorithm>

static std::vector<uint8_t> last_packet;

//changes how often corruption happens 
static constexpr double PACKET_CORRUPTION_PROB = 0.05; // 5%

void RadioLink::send(const std::vector<uint8_t>& data)
{
    last_packet = data;

    // Randomly decide whether to corrupt this packet
    static thread_local std::mt19937 rng(std::random_device{}());
    std::bernoulli_distribution corrupt_dist(PACKET_CORRUPTION_PROB);
    
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
