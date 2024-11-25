/*
 * Copyright (C) 2024 Thanasis Petsas <thanpetsas@gmail.com>
 * Licence: MIT Licence
 */

#include "DSX++.h"
#include "UDPClient.h"
#include <iostream>

#define DSX_SERVER "127.0.0.1"  // UDP Server of DSX (localhost)
#define DSX_SERVER_PORT 6969    // The default DSX Server port

using json=nlohmann::json;

// Implementations of some DSX structures' functions
// (declared in DSXProtocol)

json Instruction::toJson()
{
    json j = {
        { "type", type },
        { "parameters", parameters }
    };
    return j;
}

json Payload::toJson()
{
    std::vector<json> jsonInstructions;
    for (auto instruction : instructions) {
        jsonInstructions.push_back( instruction.toJson() );
    }
    json j = {
        { "instructions", jsonInstructions}
    };
    return j;
}

// Internal functions

/**
 * Adds an adaptive trigger instruction to the provided payload
 * This instruction configures the trigger mode and parameters
 * for the adaptive trigger
 * @param payload  The payload to receive the instruction
 * @param controllerIndex    The index of the controller to receive the trigger
 * change
 * @param trigger  The trigger (e.g., L2 or R2) to be configured
 * @param triggerMode The mode to set for the adaptive trigger
 * @param extras (optional) Additional parameters required by the trigger
 * */
void addAdaptiveTriggerToPayload(Payload &payload, int controllerIndex,
        Trigger trigger, TriggerMode triggerMode, std::vector<int> extras)
{
    // TODO: add bound checks for all the parameters
    std::vector<int> parameters = {controllerIndex, trigger, triggerMode};

    if (!extras.empty()) {
        parameters.insert(parameters.end(), extras.begin(), extras.end());
    }

    Instruction instruction(TriggerUpdate, parameters);
    payload.instructions.push_back(instruction);
}

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

    // NOTE: extras is an optional parameter (check DSX++.h for mor info)
    void setLeftTrigger(TriggerMode triggerMode, std::vector<int> extras)
    {
        addAdaptiveTriggerToPayload(payload, 0, Left, triggerMode, extras);
    }

    // NOTE: extras is an optional parameter (check DSX++.h for mor info)
    void setRightTrigger(TriggerMode triggerMode, std::vector<int> extras)
    {
        addAdaptiveTriggerToPayload(payload, 0, Right, triggerMode, extras);
    }

    int sendPayload(void)
    {
        if (payload.instructions.empty())
            return EmptyPayloadError;

        std::string payloadStr = payload.toJson().dump();

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
