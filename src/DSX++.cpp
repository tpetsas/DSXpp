/*
 * Copyright (C) 2024 Thanasis Petsas <thanpetsas@gmail.com>
 * Licence: MIT Licence
 */

#include "DSX++.h"
#include "UDPClient.h"
#include "DSXProtocol.h"
#include <iostream>

#define DSX_SERVER "127.0.0.1"  // UDP Server of DSX (localhost)
#define DSX_SERVER_PORT 6969    // The default DSX Server port

namespace DSX
{

    Payload payload;
    extern const int Success = 0;

    int init(void)
    {
        int res = UDPClient::init(DSX_SERVER, DSX_SERVER_PORT);
        if (res != UDPClient::Success) {
            std::cerr << "* UDPClient failed to initialize! (err: " <<
                        res << ")" << std::endl;
            return UDPClientInitError;
        }
        payload.instructions.clear();
        return Success;
    }

    void clearPayload(void)
    {
        payload.instructions.clear();
    }

    int sendPayload(void)
    {
        std::string payloadStr =
            "{\"instructions\":[{\"type\":1,\"parameters\":[0,1,5]}]}";

        int res = UDPClient::send(payloadStr);
        if (res != UDPClient::Success) {
            std::cerr << "* UDPClient failed to send payload! (err: " <<
                        res << ")" << std::endl;
            return SendPayloadError;
        }
        return Success;
    }

    int terminate(void)
    {
        payload.instructions.clear();
        int res = UDPClient::terminate();
        if (res != UDPClient::Success) {
            std::cerr << "* UDPClient failed to terminate! (err: " <<
                        res << ")" << std::endl;
            return UDPClientTerminateError;
        }
        return Success;
    }
}
