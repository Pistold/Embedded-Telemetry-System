#include <iostream>
#include <thread>
#include <chrono>
#include <atomic>

#include "scheduler.hpp"
#include "sensor.hpp"
#include "telemetry_packet.hpp"
#include "telemetry_serializer.hpp"
#include "radio_link.hpp"

//Global / static objects
TemperatureSensor temp_sensor;

//latest sampled temperature
std::atomic<int32_t> latest_temp_c{0};

//sample temperature sensor
void sensor_sample_task() {
    latest_temp_c = temp_sensor.read();
}

//Temperature task (easily readable results)
void telemetry_t_task() {
    //temperature packet
    TelemetryPacket packet = make_telemetry_packet(latest_temp_c.load());

    //printing
    std::cout << "[Telemetry] " 
              << "t=" << packet.timestamp_ms << " ms, "
              << "temp= " << packet.temperature_c << " C" << std::endl;
}

//serialized temperature packet task
void telemetry_tx_task()
{
    //radio link
    static RadioLink radio;

    //temperature packet
    TelemetryPacket packet = make_telemetry_packet(latest_temp_c.load());

    //serialize packet
    auto bytes = serialize_packet(packet);

    radio.send(bytes);
}


// Simulated heartbeat / watchdog task
void heartbeat_task() {
    std::cout << "[Heartbeat] System alive" << std::endl;
}

int main()
{
    Scheduler scheduler;

    // Sample sensor every 500 ms
    scheduler.add_task(sensor_sample_task, std::chrono::milliseconds(500));

    // Transmit telemetry every 1000 ms
    scheduler.add_task(telemetry_tx_task, std::chrono::milliseconds(1000));

    // Embedded-style super loop
    while (true) {
        scheduler.tick();
        //prevent 100% CPU
        std::this_thread::sleep_for(std::chrono::milliseconds(10));
    }

    return 0;
}