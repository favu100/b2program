#pragma once

#include <stdexcept>

class LoopInvariantViolation : public std::runtime_error
{
public:
    LoopInvariantViolation() : std::runtime_error("Loop invariant violation occured.")
    {

    }
};