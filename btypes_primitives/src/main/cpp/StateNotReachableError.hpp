#pragma once

#include <stdexcept>

class StateNotReachableError : public std::runtime_error
{
public:
    StateNotReachableError() : std::runtime_error("State is not reachable.")
    {

    }
};