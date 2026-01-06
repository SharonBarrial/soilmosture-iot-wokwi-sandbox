/**
 * @file SoilMoistureSensor.cpp
 * @brief Implementation file for the SoilMoistureSensor class.
 * 
 * Reads soil moisture levels using a capacitive analog sensor connected to an ESP32.
 * Converts raw analog readings to percentage of moisture for decision-making in irrigation control.
 * 
 * Project: Allpa Kawsay - IoT Agricultural Monitoring
 * 
 * @author Sharon Antuanet Ivet Barrial Marin
 * @code U202114900
 */

#include "SoilMoistureSensor.h"

/**
 * @brief Constructor for SoilMoistureSensor.
 * 
 * Initializes the sensor using the specified analog input pin.
 * 
 * @param analogPin GPIO pin where the capacitive soil moisture sensor is connected.
 */
SoilMoistureSensor::SoilMoistureSensor(uint8_t analogPin) {
  pin = analogPin;
  rawValue = 0;
}

/**
 * @brief Prepares the pin to receive analog input.
 * 
 * Call this in setup() before reading sensor values.
 */
void SoilMoistureSensor::begin() {
  pinMode(pin, INPUT);
}

/**
 * @brief Reads raw analog value from the soil moisture sensor.
 * 
 * Stores the value internally for later processing.
 */
void SoilMoistureSensor::read() {
  rawValue = analogRead(pin);
}

/**
 * @brief Converts the raw analog reading into a percentage of soil moisture.
 * 
 * Uses a linear mapping based on known dry (4095) and wet (0) values of the capacitive sensor.
 * 
 * @return float Soil moisture as a percentage (0–100%).
 */
float SoilMoistureSensor::getMoisturePercent() {
  return map(rawValue, 4095, 0, 0, 100); // dry = 4095, wet = 0
}
