/**
 * @file Device.h
 * @brief Abstract base class for all IoT devices in the Allpa Kawsay system.
 * 
 * Defines a common interface for initialization, updates, and device identification.
 * This class supports polymorphism and encapsulates generic IoT device behavior.
 * 
 * Project: Allpa Kawsay - IoT Agricultural Monitoring
 * Platform: Wokwi + ESP32 + ModestIoT
 * 
 * Author: Sharon Antuanet Ivet Barrial Marin
 * Code: U202114900
 */

#ifndef DEVICE_H
#define DEVICE_H

#include <Arduino.h>

/**
 * @class Device
 * @brief Abstract interface for any hardware component (sensor, actuator, controller).
 * 
 * Provides a unified API to ensure all devices implement basic lifecycle methods.
 */
class Device {
public:
    /**
     * @brief Initializes the device (e.g., sets pin modes, connects interfaces).
     */
    virtual void begin() = 0;

    /**
     * @brief Updates the device's internal state (e.g., reads sensor or refreshes logic).
     */
    virtual void update() = 0;

    /**
     * @brief Returns a unique identifier or description of the device.
     * 
     * @return String representing the device ID or name.
     */
    virtual String getId() = 0;

    /**
     * @brief Virtual destructor to support proper deletion via base class pointer.
     */
    virtual ~Device() {}
};

#endif // DEVICE_H
