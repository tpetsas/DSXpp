/*
 * Copyright (C) 2024 Thanasis Petsas <thanpetsas@gmail.com>
 * Licence: MIT Licence
 */

#ifndef DSXPP_H
#define DSXPP_H

#include <string>

namespace DSX {

    enum ErrorCode {
        UDPClientInitError = 1,
        UDPClientTerminateError,
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


    int sendPayload(void);


#if 0

    int setLeftTrigger();

    int setRightTrigger();

    int sendPayload();

    // TODO: Add support for:
    // - CustomTriggerMode
    // - PlayerLED
    // - MicLED

#endif

    /**
     * Initializes a DSX++ client
     * @return 0 if the client was successfully terminated,
     *         or an error code otherwise (see enum class ErrorCode)
     */
    int terminate(void);
}

#endif // DSXPP_H
