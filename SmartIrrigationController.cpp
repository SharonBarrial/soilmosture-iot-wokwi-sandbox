/**
 * @file SmartIrrigationController.cpp
 * @brief Implements the logic of an intelligent irrigation controller using the ModestIoT pattern.
 * 
 * This class coordinates soil moisture readings, environmental data acquisition, and 
 * solenoid valve control. It supports AUTO and MANUAL operation modes and reports 
 * device status every 5 seconds in JSON format via serial output.
 * 
 * Project: Allpa Kawsay - Smart Agriculture IoT Platform
 * Platform: ESP32 on Wokwi
 * 
 * @author Author: Sharon Antuanet Ivet Barrial Marin
 * @code Code: U202114900
 */

#include "SmartIrrigationController.h"
#include <OneWire.h>
#include <WiFi.h>
#include "time.h"

/// WiFi credentials for Wokwi simulation
const char* WIFI_SSID = "Wokwi-GUEST";
const char* WIFI_PASSWORD = "";

/**
 * @brief Constructor for the SmartIrrigationController class.
 * 
 * Initializes all internal components (soil sensor, ambient sensor, valve) and sets
 * the default irrigation mode to AUTO.
 * 
 * @param macAddr The MAC address of the device, used for identifying the node in reports.
 */
SmartIrrigationController::SmartIrrigationController(String macAddr)
  : mac(macAddr), soilSensor(34), ambientSensor(4), valve(12), mode("AUTO"), lastUpdate(0) {}

/**
 * @brief Initializes all components and displays device metadata.
 * 
 * Establishes WiFi connection (Wokwi simulation), and initializes the sensors and actuator.
 */
void SmartIrrigationController::begin() {
  WiFi.mode(WIFI_STA);
  WiFi.begin(WIFI_SSID, WIFI_PASSWORD);
  
  Serial.print("Connecting... ");
  Serial.println("WiFi connected");
  Serial.println("ALLPA KAWSAY S.A. - IoT Irrigation Controller");
  Serial.println("Developer: Sharon Antuanet Ivet Barrial Marin");
  Serial.println("Student Code: U202114900");

  soilSensor.begin();
  ambientSensor.begin();
  valve.begin();
}

/**
 * @brief Changes the irrigation mode of the system.
 * 
 * Allows external command handlers to switch between AUTO and MANUAL modes.
 * If the input is invalid, the mode is not changed.
 * 
 * @param newMode A string specifying the desired operation mode ("AUTO" or "MANUAL").
 */
void SmartIrrigationController::setMode(String newMode) {
  if (newMode == "AUTO" || newMode == "MANUAL") {
    mode = newMode;
    Serial.print("Irrigation mode changed to: ");
    Serial.println(mode);
  }
}

/**
 * @brief Main update logic for irrigation control and data reporting.
 * 
 * - Reads data from sensors.
 * - In AUTO mode, controls the solenoid valve based on soil moisture.
 * - Automatically switches to MANUAL mode if the soil is too wet.
 * - Every 5 seconds, sends a JSON-formatted report to the serial console.
 */
void SmartIrrigationController::update() {
  soilSensor.read();
  ambientSensor.read();

  float moisture = soilSensor.getMoisturePercent();

  // Auto-switch to MANUAL mode if soil is too wet
  if (mode == "AUTO" && moisture > 80.0) {
    mode = "MANUAL";
    valve.close();
    Serial.println("Excessive moisture detected. Switching to MANUAL mode.");
  }

  // AUTO mode control logic
  if (mode == "AUTO") {
    if (moisture < 40.0) {
      valve.open();
    } else {
      valve.close();
    }
  }

  // JSON status report every 5 seconds
  if (millis() - lastUpdate >= 5000) {
    lastUpdate = millis();

    Serial.print(F("{\"deviceMacAddress\":\""));
    Serial.print(mac);
    Serial.print(F("\",\"operationMode\":\""));
    Serial.print(mode);
    Serial.print(F("\",\"currentSoilMoisture\":"));
    Serial.print(moisture, 1);
    Serial.print(F(",\"ambientTemperature\":"));
    Serial.print(ambientSensor.getTemperature(), 1);
    Serial.print(F(",\"ambientHumidity\":"));
    Serial.print(ambientSensor.getHumidity(), 1);
    Serial.print(F(",\"createdAt\":\""));
    Serial.print(__DATE__);
    Serial.print(F(" "));
    Serial.print(__TIME__);
    Serial.println(F("\"}"));
  }
}
