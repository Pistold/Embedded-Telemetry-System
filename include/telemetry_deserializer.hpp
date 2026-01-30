#ifndef TELEMETRY_DESERIALIZER_HPP
#define TELEMETRY_DESERIALIZER_HPP

#include <vector>
#include <cstdint>
#include <optional>

#include "telemetry_packet.hpp"

/*
 * Deserialize binary telemetry packets
 * Returns std::nullopt if CRC check fails
 */
std::optional<TelemetryPacket>
deserialize_packet(const std::vector<uint8_t>& buffer);

#endif // TELEMETRY_DESERIALIZER_HPP
