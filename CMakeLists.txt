cmake_minimum_required(VERSION 3.16)

project(embedded_telemetry_system LANGUAGES CXX)

# Use C++17 standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

# Add the executable and main source file
add_executable(telemetry
    src/main.cpp
    src/scheduler.cpp
    src/sensor.cpp
    src/telemetry_packet.cpp
)

# Include header files
target_include_directories(telemetry PRIVATE include)