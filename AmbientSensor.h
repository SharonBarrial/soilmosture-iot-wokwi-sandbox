/**
 * @file AmbientSensor.h
 * @brief Header file for the AmbientSensor class.
 * 
 * This class encapsulates the logic for reading environmental data (temperature and humidity)
 * using a DHT22 sensor. Intended for integration in the Allpa Kawsay IoT device,
 * applying the ModestIoT object-oriented pattern.
 * 
 * @author Sharon Barrial
 * @code U202114900
 */

#ifndef AMBIENT_SENSOR_H
#define AMBIENT_SENSOR_H

#include <DHT.h>

/**
 * @class AmbientSensor
 * @brief Class that manages a DHT22 sensor to monitor ambient temperature and humidity.
 * 
 * Provides methods to initialize the sensor, perform readings, and retrieve the latest
 * temperature and humidity values.
 */
class AmbientSensor {
  private:
    DHT dht;               ///< Instance of the DHT sensor.
    float temperature;     ///< Last measured temperature (°C).
    float humidity;        ///< Last measured humidity (%).

  public:
    /**
     * @brief Constructor for AmbientSensor.
     * 
     * Initializes the DHT22 sensor on the specified pin.
     * 
     * @param pin The GPIO pin where the DHT22 is connected.
     */
    AmbientSensor(uint8_t pin);

    /**
     * @brief Initializes the DHT sensor.
     * 
     * Call this method in setup() before using the sensor.
     */
    void begin();

    /**
     * @brief Reads current values from the sensor and stores them internally.
     */
    void read();

    /**
     * @brief Gets the last read temperature value.
     * 
     * @return float Temperature in degrees Celsius.
     */
    float getTemperature();

    /**
     * @brief Gets the last read humidity value.
     * 
     * @return float Relative humidity in percentage.
     */
    float getHumidity();
};

#endif // AMBIENT_SENSOR_H
