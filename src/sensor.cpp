#include "sensor.hpp"
#include <cstdlib>

//Simulate a slowly changing temperature
int32_t TemperatureSensor::read()
{
    // Add small random drift to temperature(-1, 0, +1) 
    int delta = (std::rand() % 3) - 1;
    current_ += delta;
    return current_;
}