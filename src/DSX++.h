/*
 * Copyright (C) 2024 Thanasis Petsas <thanpetsas@gmail.com>
 * Licence: MIT Licence
 */

#ifndef DSXPP_H
#define DSXPP_H

#include "DSXProtocol.h"

#include <string>
#include <vector>


namespace DSX {

    enum ErrorCode {
        UDPClientInitError = 1,
        UDPClientTerminateError,
        EmptyPayloadError,
        SendPayloadError
    };

    extern const int Success;

    /**
     * Initializes a DSX++ client for sending dualsense features requests
     * @return 0 if the client was successfully initialized,
     *         or an error code otherwise (see enum class ErrorCode)
     */
    int init(void);

    /**
     * Clears the current payload of instruction of DSX++ client so
     * that a new set of instructions can be added
     */
    void clearPayload(void);

    /**
     * Sends the currently constucted payload of instructions to DSX server
     * in order to be applied to the controller
     */
    int sendPayload(void);

    /**
    * Sets an adaptive trigger mode to the left trigger (i.e., L2)
    * @param triggerMode The mode to set for the adaptive trigger
    * @param extras (optional) Additional parameters required by the trigger
    *
    * NOTE: The controller index used is 0. If there's a need of another
    * index, a new function should be introduced that takes an extra parameter
    *
    * extras: for more info about this argument check the following page:
    * https://github.com/Paliverse/DSX/tree/main/Mod%20System%20(DSX%20v3)#adaptive-triggers
    */
    void setLeftTrigger(TriggerMode triggerMode, std::vector<int> extras={});

    /**
    * Sets an adaptive trigger mode to the right trigger (i.e., R2)
    * @param triggerMode The mode to set for the adaptive trigger
    * @param extras (optional) Additional parameters required by the trigger
    *
    * NOTE: The controller index used is 0. If there's a need of another
    * index, a new function should be introduced that takes an extra parameter
    *
    * extras: for more info about this argument check the following page:
    * https://github.com/Paliverse/DSX/tree/main/Mod%20System%20(DSX%20v3)#adaptive-triggers
    */
    void setRightTrigger(TriggerMode triggerMode, std::vector<int> extras={});

    // TODO: Add support for:
    // - CustomTriggerMode
    // - PlayerLED
    // - MicLED

    /**
     * Initializes a DSX++ client
     * @return 0 if the client was successfully terminated,
     *         or an error code otherwise (see enum class ErrorCode)
     */
    int terminate(void);
}

#endif // DSXPP_H
