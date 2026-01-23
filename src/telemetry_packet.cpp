#include "telemetry_packet.hpp"

TelemetryPacket make_telemetry_packet(int32_t temperature_c)
{
    auto now = std::chrono::steady_clock::now();
    auto ms = std::chrono::duration_cast<std::chrono::milliseconds>(now.time_since_epoch()).count();

    TelemetryPacket packet;
    packet.timestamp_ms = static_cast<uint64_t>(ms);
    packet.temperature_c = temperature_c;

    return packet;
}
