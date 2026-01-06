/**
 * @file ValveActuator.cpp
 * @brief Implementation file for the ValveActuator class.
 * 
 * Controls a solenoid valve (simulated with a relay module) for irrigation.
 * This class abstracts the actuator logic to open or close the water flow.
 * 
 * Project: Allpa Kawsay - IoT Agricultural Monitoring
 * 
 * @author Sharon Antuanet Ivet Barrial Marin
 * @code U202114900
 */

#include "ValveActuator.h"

/**
 * @brief Constructor for ValveActuator.
 * 
 * Stores the digital output pin connected to the relay module.
 * 
 * @param pin GPIO output pin used to control the valve relay.
 */
ValveActuator::ValveActuator(uint8_t pin) {
  this->pin = pin;
}

/**
 * @brief Initializes the actuator pin.
 * 
 * Sets the pin mode to OUTPUT and ensures the valve starts in closed state.
 */
void ValveActuator::begin() {
  pinMode(pin, OUTPUT);
  digitalWrite(pin, LOW); // Closed by default
}

/**
 * @brief Opens the irrigation valve by activating the relay.
 */
void ValveActuator::open() {
  digitalWrite(pin, HIGH);
}

/**
 * @brief Closes the irrigation valve by deactivating the relay.
 */
void ValveActuator::close() {
  digitalWrite(pin, LOW);
}
