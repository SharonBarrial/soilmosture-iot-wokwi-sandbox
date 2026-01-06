/**
 * @file CommandHandler.h
 * @brief Abstract interface for handling incoming commands in an IoT device.
 * 
 * This class defines the base for all command handlers in the Allpa Kawsay system.
 * It can be implemented by controllers or services that react to remote control actions,
 * such as switching irrigation modes or setting thresholds.
 * 
 * Project: Allpa Kawsay - IoT Agricultural Monitoring
 * Platform: ESP32 + ModestIoT
 * 
 * @author Author: Sharon Antuanet Ivet Barrial Marin
 * @code Code: U202114900
 */

#ifndef COMMAND_HANDLER_H
#define COMMAND_HANDLER_H

#include <Arduino.h>

/**
 * @class CommandHandler
 * @brief Interface for handling string-based commands and their associated payloads.
 */
class CommandHandler {
public:
    /**
     * @brief Processes an incoming command.
     * 
     * This method should be implemented by derived classes to interpret and act on specific commands.
     * 
     * @param command The name or type of the command (e.g., "SET_MODE").
     * @param payload Optional data or parameters associated with the command.
     */
    virtual void handleCommand(const String& command, const String& payload) = 0;

    /**
     * @brief Virtual destructor to allow proper cleanup from base pointers.
     */
    virtual ~CommandHandler() {}
};

#endif // COMMAND_HANDLER_H
