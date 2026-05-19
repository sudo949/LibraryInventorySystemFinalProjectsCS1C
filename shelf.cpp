#include "shelf.h"

#include <stdexcept>
#include <string>

Item& Shelf::operator[](std::size_t compartment_index)
{
    Compartment& compartment = get_compartment(compartment_index);
    if (compartment.is_empty())
    {
        throw std::runtime_error(
            "Cannot access an item from empty compartment index " +
            std::to_string(compartment_index) +
            "."
        );
    }

    return *compartment.get_item();
}

const Item& Shelf::operator[](std::size_t compartment_index) const
{
    const Compartment& compartment = get_compartment(compartment_index);
    if (compartment.is_empty())
    {
        throw std::runtime_error(
            "Cannot access an item from empty compartment index " +
            std::to_string(compartment_index) +
            "."
        );
    }

    return *compartment.get_item();
}

std::size_t Shelf::get_compartment_count() const
{
    return _compartments.size();
}

Compartment& Shelf::get_compartment(std::size_t compartment_index)
{
    if (compartment_index >= _compartments.size())
    {
        throw std::out_of_range(
            "Compartment index " + std::to_string(compartment_index) + " is out of range."
        );
    }

    return _compartments[compartment_index];
}

const Compartment& Shelf::get_compartment(std::size_t compartment_index) const
{
    if (compartment_index >= _compartments.size())
    {
        throw std::out_of_range(
            "Compartment index " + std::to_string(compartment_index) + " is out of range."
        );
    }

    return _compartments[compartment_index];
}
