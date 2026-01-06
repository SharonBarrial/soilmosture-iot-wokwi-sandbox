/**
 * @file SmartIrrigationController.h
 * @brief Header file for the SmartIrrigationController class.
 * 
 * Coordinates sensors and actuators for automated or manual irrigation control
 * based on soil and ambient conditions. Reports system status via serial in JSON format.
 * This class is a high-level controller within the ModestIoT framework.
 * 
 * Project: Allpa Kawsay - IoT Agricultural Monitoring
 * Platform: ESP32 (Wokwi) + Arduino Sketch + ModestIoT
 * 
 * Author: Sharon Antuanet Ivet Barrial Marin
 * Code: U202114900
 */

#ifndef SMART_IRRIGATION_CONTROLLER_H
#define SMART_IRRIGATION_CONTROLLER_H

#include "SoilMoistureSensor.h"
#include "AmbientSensor.h"
#include "ValveActuator.h"

/**
 * @class SmartIrrigationController
 * @brief Manages the full lifecycle of an intelligent irrigation device.
 * 
 * Controls the irrigation valve based on soil moisture readings and operational mode (AUTO or MANUAL),
 * acquires ambient sensor data, and reports status periodically.
 */
class SmartIrrigationController {
  private:
    String mac;                     ///< MAC address of the device (used in JSON reports).
    SoilMoistureSensor soilSensor; ///< Soil moisture sensor instance (capacitive sensor).
    AmbientSensor ambientSensor;   ///< Ambient temperature/humidity sensor instance (DHT22).
    ValveActuator valve;           ///< Solenoid valve actuator controlled via relay.
    String mode;                   ///< Operation mode: "AUTO" or "MANUAL".
    unsigned long lastUpdate;      ///< Timestamp of the last status report (in millis).

  public:
    /**
     * @brief Constructor for SmartIrrigationController.
     * 
     * Initializes internal sensor and actuator components.
     * 
     * @param macAddr MAC address string used for device identification in the system.
     */
    SmartIrrigationController(String macAddr);

    /**
     * @brief Initializes all sensors, actuators, and network connection.
     * 
     * Must be called in the Arduino `setup()` method to prepare the device.
     */
    void begin();

    /**
     * @brief Executes the main control logic and data reporting.
     * 
     * Should be called repeatedly in the Arduino `loop()` function.
     * - Reads sensors.
     * - Controls valve (in AUTO mode).
     * - Outputs JSON report every 5 seconds.
     */
    void update();

    /**
     * @brief Manually sets the irrigation mode.
     * 
     * Accepts either "AUTO" (automatic control) or "MANUAL" (no automatic actions).
     * If input is invalid, no change is made.
     * 
     * @param newMode A string specifying the new irrigation mode ("AUTO" or "MANUAL").
     */
    void setMode(String newMode);
};

#endif // SMART_IRRIGATION_CONTROLLER_H
