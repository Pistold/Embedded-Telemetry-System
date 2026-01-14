#ifndef SENSOR_HPP
#define SENSOR_HPP

#include <cstdint>


class Sensor {
public:
    virtual ~Sensor() = default;

    // Read a sensor value
    virtual int32_t read() = 0;
};

// Simulated temperature sensor
class TemperatureSensor : public Sensor {
public:
    int32_t read() override;

private:
    int32_t current_ = 25; // start at 25C
};

#endif // SENSOR_HPP