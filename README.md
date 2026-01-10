# Embedded Telemetry System

Embedded-style sensor data acquisition and telemetry system in C++

This project implements an embedded-style telemetry system in C++, designed using deterministic scheduling, fixed-format binary packets, and simulated sensor inputs. The system models how embedded flight or mission software is developed and tested in a Linux environment prior to deployment on target hardware.

The application periodically acquires data from multiple simulated sensors, packages the data into fixed-size telemetry frames with checksum validation, and transmits the data over a lightweight transport layer. System health is continuously monitored using watchdog and fault-detection logic to ensure reliable operation under simulated fault conditions.

## Features
- Deterministic main loop with fixed-cycle scheduling
- Simulated multi-sensor data acquisition
- Fixed-format binary telemetry packets with checksum validation
- Modular transport layer
- Health monitoring and watchdog-based fault detection

## Build (Planned)
- C++
- CMake
- Linux / POSIX environment