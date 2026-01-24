#include "telemetry_serializer.hpp"

std::vector<uint8_t> serialize_packet(const TelemetryPacket& packet)
{
    std::vector<uint8_t> buffer;
    buffer.reserve(sizeof(TelemetryPacket));

    // Serialize timestamp (uint64_t)
    for (int i = 0; i < 8; ++i) {
        buffer.push_back(
            static_cast<uint8_t>((packet.timestamp_ms >> (i * 8)) & 0xFF));
    }

    // Serialize temperature (int32_t)
    for (int i = 0; i < 4; ++i) {
        buffer.push_back(
            static_cast<uint8_t>((packet.temperature_c >> (i * 8)) & 0xFF));
    }

    return buffer;
}
