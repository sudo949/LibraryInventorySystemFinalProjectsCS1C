#ifndef SHELF_H
#define SHELF_H

#include "library_compartment.h"

#include <array>
#include <cstddef>

class Shelf
{
public:
    static constexpr std::size_t k_compartment_count = 15U;

    Item& operator[](std::size_t compartment_index);
    const Item& operator[](std::size_t compartment_index) const;

    std::size_t get_compartment_count() const;
    Compartment& get_compartment(std::size_t compartment_index);
    const Compartment& get_compartment(std::size_t compartment_index) const;

private:
    std::array<Compartment, k_compartment_count> _compartments;
};

#endif // SHELF_H
