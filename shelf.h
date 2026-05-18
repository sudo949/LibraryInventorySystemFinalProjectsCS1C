#ifndef SHELF_H
#define SHELF_H

#include "library_compartment.h"

#include <array>
#include <cstddef>

class Shelf
{
public:
    static constexpr std::size_t k_compartment_count = 15U;

    Compartment& operator[](std::size_t compartment_index);
    const Compartment& operator[](std::size_t compartment_index) const;

    std::size_t get_compartment_count() const;

private:
    std::array<Compartment, k_compartment_count> _compartments;
};

#endif // SHELF_H
