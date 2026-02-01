#include "telemetry_deserializer.hpp"
#include "crc8.hpp"

std::optional<TelemetryPacket>
deserialize_packet(const std::vector<uint8_t>& buffer)
{
    // Must contain timestamp (8) + temp (4) + CRC (1)
    if (buffer.size() != 13)
        return std::nullopt;

    // Separate payload and CRC
    std::vector<uint8_t> payload(buffer.begin(), buffer.end() - 1);
    uint8_t received_crc = buffer.back();

    if (crc8(payload) != received_crc)
        return std::nullopt;

    TelemetryPacket packet{};

    // Deserialize timestamp
    packet.timestamp_ms = 0;
    for (int i = 0; i < 8; ++i) {
        packet.timestamp_ms |=
            static_cast<uint64_t>(payload[i]) << (i * 8);
    }

    // Deserialize temperature
    packet.temperature_c = 0;
    for (int i = 0; i < 4; ++i) {
        packet.temperature_c |=
            static_cast<int32_t>(payload[8 + i]) << (i * 8);
    }

    return packet;
}
