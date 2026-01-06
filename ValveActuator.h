/**
 * @file ValveActuator.h
 * @brief Header file for the ValveActuator class.
 * 
 * This class controls a solenoid valve via a digital output pin (typically using a relay module).
 * It abstracts the functionality to open or close the valve for irrigation purposes.
 * 
 * Project: Allpa Kawsay - IoT Agricultural Monitoring
 * 
 * @author Sharon Antuanet Ivet Barrial Marin
 * @code U202114900
 */

#ifndef VALVE_ACTUATOR_H
#define VALVE_ACTUATOR_H

#include <Arduino.h>

/**
 * @class ValveActuator
 * @brief Controls a digital actuator (relay) to open or close a solenoid irrigation valve.
 */
class ValveActuator {
  private:
    uint8_t pin; ///< GPIO pin connected to the relay controlling the valve.

  public:
    /**
     * @brief Constructor for ValveActuator.
     * @param pin GPIO pin used to control the valve.
     */
    ValveActuator(uint8_t pin);

    /**
     * @brief Initializes the actuator pin as output and sets the valve to closed state.
     */
    void begin();

    /**
     * @brief Opens the valve by setting the pin HIGH.
     */
    void open();

    /**
     * @brief Closes the valve by setting the pin LOW.
     */
    void close();
};

#endif // VALVE_ACTUATOR_H
