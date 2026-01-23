#ifndef TELEMETRY_PACKET_HPP
#define TELEMETRY_PACKET_HPP

#include <cstdint>
#include <chrono>

/*
 * Telemetry packet representing a single sensor sample
 */
struct TelemetryPacket {
    uint64_t timestamp_ms;   // milliseconds since steady clock epoch
    int32_t temperature_c;   // temperature in Celsius
};

/*
 * Utility function to create telemetry packets
 */
TelemetryPacket make_telemetry_packet(int32_t temperature_c);

#endif // TELEMETRY_PACKET_HPP
