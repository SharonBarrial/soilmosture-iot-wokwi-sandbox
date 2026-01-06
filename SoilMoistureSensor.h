/**
 * @file SoilMoistureSensor.h
 * @brief Header file for the SoilMoistureSensor class.
 * 
 * Encapsulates functionality for reading soil moisture using a capacitive analog sensor.
 * Provides methods to initialize the pin, perform analog reads, and convert values to percentage.
 * 
 * Project: Allpa Kawsay - IoT Agricultural Monitoring
 * 
 * @author Sharon Antuanet Ivet Barrial Marin
 * @code U202114900
 */

#ifndef SOIL_MOISTURE_SENSOR_H
#define SOIL_MOISTURE_SENSOR_H

#include <Arduino.h>

/**
 * @class SoilMoistureSensor
 * @brief Handles readings from a capacitive soil moisture sensor connected to an ESP32 analog pin.
 */
class SoilMoistureSensor {
  private:
    uint8_t pin;       ///< Analog pin connected to the sensor.
    int rawValue;      ///< Last raw analog value read from the sensor.

  public:
    /**
     * @brief Constructor for SoilMoistureSensor.
     * @param analogPin GPIO analog pin connected to the moisture sensor.
     */
    SoilMoistureSensor(uint8_t analogPin);

    /**
     * @brief Initializes the pin as input.
     */
    void begin();

    /**
     * @brief Reads the current raw analog value from the sensor.
     */
    void read();

    /**
     * @brief Gets the converted soil moisture value in percentage.
     * 
     * Maps raw sensor values (dry = 4095, wet = 0) to a 0–100% scale.
     * 
     * @return float Soil moisture percentage.
     */
    float getMoisturePercent();
};

#endif // SOIL_MOISTURE_SENSOR_H
