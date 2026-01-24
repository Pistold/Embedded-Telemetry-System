#ifndef TELEMETRY_SERIALIZER_HPP
#define TELEMETRY_SERIALIZER_HPP

#include <vector>
#include <cstdint>

#include "telemetry_packet.hpp"

/*
 * Serialize telemetry packets into a binary buffer
 * (transport-agnostic)
 */
std::vector<uint8_t> serialize_packet(const TelemetryPacket& packet);

#endif // TELEMETRY_SERIALIZER_HPP
