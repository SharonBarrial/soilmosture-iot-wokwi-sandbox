/**
 * @file EventHandler.h
 * @brief Abstract interface for handling system events in the Allpa Kawsay IoT platform.
 * 
 * This class defines the base contract for components that respond to system or device-level events.
 * It can be used to trigger logs, notifications, alerts or act on sensor thresholds.
 * 
 * Project: Allpa Kawsay - IoT Agricultural Monitoring
 * Platform: ESP32 + ModestIoT
 * 
 * @author: Author: Sharon Antuanet Ivet Barrial Marin
 * @code Code: U202114900
 */

#ifndef EVENT_HANDLER_H
#define EVENT_HANDLER_H

#include <Arduino.h>

/**
 * @class EventHandler
 * @brief Interface for reacting to events emitted by sensors, actuators, or system logic.
 */
class EventHandler {
public:
    /**
     * @brief Handles an emitted event.
     * 
     * This method must be implemented by derived classes to process a given event type and its data.
     * 
     * @param eventType A string representing the type of event (e.g., "MOISTURE_LOW", "VALVE_OPENED").
     * @param data Additional information or payload related to the event (e.g., moisture value).
     */
    virtual void handleEvent(const String& eventType, const String& data) = 0;

    /**
     * @brief Virtual destructor to ensure proper cleanup in derived classes.
     */
    virtual ~EventHandler() {}
};

#endif // EVENT_HANDLER_H
