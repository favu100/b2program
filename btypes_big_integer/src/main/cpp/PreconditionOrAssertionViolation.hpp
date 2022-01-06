#pragma once

#include <stdexcept>

class PreconditionOrAssertionViolation : public std::runtime_error
{
public:
    PreconditionOrAssertionViolation() : std::runtime_error("Precondition or assertion violation occured.")
    {

    }
};