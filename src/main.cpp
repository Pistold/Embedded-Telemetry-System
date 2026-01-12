#include <iostream>
#include <thread>
#include <chrono>

#include "scheduler.hpp"

// Simulated telemetry task
void telemetry_task()
{
    static int counter = 0;
    std::cout << "[Telemetry] Sample #" << counter++ << std::endl;
}

// Simulated heartbeat / watchdog task
void heartbeat_task()
{
    std::cout << "[Heartbeat] System alive" << std::endl;
}

int main()
{
    Scheduler scheduler;

    // Add tasks with different execution periods
    scheduler.add_task(telemetry_task, std::chrono::milliseconds(1000));
    scheduler.add_task(heartbeat_task, std::chrono::milliseconds(500));

    // Main loop (embedded-style super loop)
    while (true) {
        scheduler.tick();

        // Prevent 100% CPU usage
        std::this_thread::sleep_for(std::chrono::milliseconds(10));
    }

    return 0;
}