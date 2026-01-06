/**
 * @file sketch.ino
 * @brief Main Arduino sketch for the Smart Irrigation IoT device.
 * 
 * This sketch initializes the SmartIrrigationController and repeatedly calls its update method.
 * It supports both AUTO and MANUAL modes of irrigation and sends JSON-formatted status reports.
 * 
 * Project: Allpa Kawsay - IoT Agricultural Monitoring
 * Platform: Wokwi + ESP32
 * 
 * @author Developer: Sharon Antuanet Ivet Barrial Marin
 * @code Code: U202114900
 */

#include "SmartIrrigationController.h"

// Create an instance of the controller with a mock MAC address
SmartIrrigationController controller("AA:BB:CC:DD:EE:FF");

/**
 * @brief Arduino setup function.
 * 
 * Initializes the serial monitor and the irrigation controller components.
 */
void setup() {
  Serial.begin(9600);
  controller.begin();
}

/**
 * @brief Arduino loop function.
 * 
 * Periodically calls the controller's update method to manage sensor readings,
 * automatic irrigation logic, and JSON status reporting.
 */
void loop() {
  controller.update();
  delay(100); // Slight delay to avoid overloading CPU
}
