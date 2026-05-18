#ifndef LIBRARY_STORAGE_H
#define LIBRARY_STORAGE_H

#include "compartment_location.h"
#include "library_item.h"
#include "operation_result.h"
#include "shelf.h"

#include <cstddef>
#include <iosfwd>
#include <memory>
#include <string>
#include <vector>

class LibraryStorage
{
public:
    explicit LibraryStorage(std::size_t shelf_count);

    Shelf& operator[](std::size_t shelf_index);
    const Shelf& operator[](std::size_t shelf_index) const;

    std::size_t get_shelf_count() const;

    OperationResult add_item(std::unique_ptr<Item> item, const CompartmentLocation& location);
    OperationResult check_out_item(
        const CompartmentLocation& location,
        const std::string& person_name,
        const std::string& due_date
    );
    OperationResult check_in_item(const CompartmentLocation& location);
    OperationResult swap_items(
        const CompartmentLocation& first_location,
        const CompartmentLocation& second_location
    );
    void print_items_in_storage(std::ostream& output_stream) const;
    void print_checked_out_items(std::ostream& output_stream) const;

private:
    bool is_valid_location(const CompartmentLocation& location) const;
    std::string format_location(const CompartmentLocation& location) const;
    Compartment& get_compartment(const CompartmentLocation& location);
    const Compartment& get_compartment(const CompartmentLocation& location) const;

    std::vector<Shelf> _shelves;
};

#endif // LIBRARY_STORAGE_H
