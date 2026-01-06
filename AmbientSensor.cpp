/**
 * @file AmbientSensor.cpp
 * @brief Implementation file for the AmbientSensor class.
 * 
 * Provides functionality to read environmental temperature and humidity using a DHT22 sensor.
 * Designed for the Allpa Kawsay IoT device, using ModestIoT object-oriented patterns.
 * 
 * @author Sharon Barrial
 * @code U202114900
 */

#include "AmbientSensor.h"

/**
 * @brief Constructor for AmbientSensor.
 * 
 * Initializes the DHT sensor on the specified pin.
 * 
 * @param pin The GPIO pin connected to the DHT22 sensor.
 */
AmbientSensor::AmbientSensor(uint8_t pin) : dht(pin, DHT22) {}

/**
 * @brief Initializes the DHT sensor.
 * 
 * Must be called once in the setup() function before using read().
 */
void AmbientSensor::begin() {
  dht.begin();
}

/**
 * @brief Reads the current temperature and humidity values from the DHT sensor.
 * 
 * The values are stored internally for later retrieval using getter methods.
 */
void AmbientSensor::read() {
  temperature = dht.readTemperature();
  humidity = dht.readHumidity();
}

/**
 * @brief Returns the last read temperature value.
 * 
 * @return float Temperature in degrees Celsius.
 */
float AmbientSensor::getTemperature() {
  return temperature;
}

/**
 * @brief Returns the last read humidity value.
 * 
 * @return float Relative humidity in percentage.
 */
float AmbientSensor::getHumidity() {
  return humidity;
}
