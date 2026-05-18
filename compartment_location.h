#ifndef COMPARTMENT_LOCATION_H
#define COMPARTMENT_LOCATION_H

#include <cstddef>

struct CompartmentLocation
{
    std::size_t shelf_index;
    std::size_t compartment_index;
};

#endif // COMPARTMENT_LOCATION_H
