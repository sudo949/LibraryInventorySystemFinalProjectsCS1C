#include "shelf.h"

#include <stdexcept>
#include <string>

Compartment& Shelf::operator[](std::size_t compartment_index)
{
    if (compartment_index >= _compartments.size())
    {
        throw std::out_of_range(
            "Compartment index " + std::to_string(compartment_index) + " is out of range."
        );
    }

    return _compartments[compartment_index];
}

const Compartment& Shelf::operator[](std::size_t compartment_index) const
{
    if (compartment_index >= _compartments.size())
    {
        throw std::out_of_range(
            "Compartment index " + std::to_string(compartment_index) + " is out of range."
        );
    }

    return _compartments[compartment_index];
}

std::size_t Shelf::get_compartment_count() const
{
    return _compartments.size();
}
