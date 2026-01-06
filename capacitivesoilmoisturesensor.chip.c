// Wokwi Custom Chip - For docs and examples see:
// https://docs.wokwi.com/chips-api/getting-started
//
// SPDX-License-Identifier: MIT
// Copyright 2025 Sharon Barrial

/**
 * @file chip.c
 * @brief Custom Wokwi chip that simulates a capacitive soil moisture sensor.
 * 
 * This chip provides:
 * - A humidity output that varies between 0% and 100%.
 * - Two input pins to simulate increase or decrease of humidity.
 * - An analog output pin that can be read by a microcontroller (e.g., ESP32).
 * 
 * Project: Allpa Kawsay - IoT Smart Irrigation System
 * Author: Sharon Antuanet Ivet Barrial Marin
 * Code: U202114900
 */

#include "wokwi-api.h"
#include <stdio.h>
#include <stdlib.h>

typedef struct {
  int humidity;
  pin_t pin_increase;
  pin_t pin_decrease;
  pin_t pin_out;  
} chip_state_t;

/**
 * @brief Initializes the custom moisture sensor chip.
 * 
 * Sets the initial humidity level, configures input/output pins,
 * and registers pin change callbacks.
 */

void chip_init() {
  chip_state_t *chip = malloc(sizeof(chip_state_t));

  chip->humidity = 50; // humedad inicial

  // Asigna pines
  //chip->pin_increase = pin_init("INCREASE", INPUT);
  //chip->pin_decrease = pin_init("DECREASE", INPUT);
  //chip->pin_out = pin_init("HUMIDITY_OUT", OUTPUT);

  // Establecer callbacks
  //pin_set_pull(chip->pin_increase, PULL_UP);
  //pin_set_pull(chip->pin_decrease, PULL_UP);

  //pin_watch(chip->pin_increase, button_changed, chip);
  //pin_watch(chip->pin_decrease, button_changed, chip);

  printf("Custom Humidity Chip listo (50%% inicial)\n");
}

