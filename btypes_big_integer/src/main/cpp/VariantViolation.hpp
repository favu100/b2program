#pragma once

#include <stdexcept>

class VariantViolation : public std::runtime_error
{
public:
    VariantViolation() : std::runtime_error("Variant violation occured.")
    {

    }
};