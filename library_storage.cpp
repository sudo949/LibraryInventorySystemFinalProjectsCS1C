#include "library_storage.h"

#include <ostream>
#include <stdexcept>
#include <string>

LibraryStorage::LibraryStorage(std::size_t shelf_count)
    : _shelves(shelf_count)
{
}

Shelf& LibraryStorage::operator[](std::size_t shelf_index)
{
    if (shelf_index >= _shelves.size())
    {
        throw std::out_of_range(
            "Shelf index " + std::to_string(shelf_index) + " is out of range."
        );
    }

    return _shelves[shelf_index];
}

const Shelf& LibraryStorage::operator[](std::size_t shelf_index) const
{
    if (shelf_index >= _shelves.size())
    {
        throw std::out_of_range(
            "Shelf index " + std::to_string(shelf_index) + " is out of range."
        );
    }

    return _shelves[shelf_index];
}

std::size_t LibraryStorage::get_shelf_count() const
{
    return _shelves.size();
}

OperationResult LibraryStorage::add_item(std::unique_ptr<Item> item, const CompartmentLocation& location)
{
    if (!is_valid_location(location))
    {
        return {false, "Cannot add an item to invalid location " + format_location(location) + "."};
    }

    if (item == nullptr)
    {
        return {false, "Cannot add a null item to storage."};
    }

    Compartment& compartment = get_compartment(location);
    if (!compartment.is_empty())
    {
        return {false, "Cannot add an item to occupied location " + format_location(location) + "."};
    }

    compartment.set_item(std::move(item));
    return {true, "Item added successfully to " + format_location(location) + "."};
}

OperationResult LibraryStorage::check_out_item(
    const CompartmentLocation& location,
    const std::string& person_name,
    const std::string& due_date
)
{
    if (!is_valid_location(location))
    {
        return {false, "Cannot check out an item from invalid location " + format_location(location) + "."};
    }

    return get_compartment(location).checkout_item(person_name, due_date);
}

OperationResult LibraryStorage::check_in_item(const CompartmentLocation& location)
{
    if (!is_valid_location(location))
    {
        return {false, "Cannot check in an item from invalid location " + format_location(location) + "."};
    }

    return get_compartment(location).checkin_item();
}

OperationResult LibraryStorage::swap_items(
    const CompartmentLocation& first_location,
    const CompartmentLocation& second_location
)
{
    if (!is_valid_location(first_location))
    {
        return {false, "Cannot swap from invalid location " + format_location(first_location) + "."};
    }

    if (!is_valid_location(second_location))
    {
        return {false, "Cannot swap from invalid location " + format_location(second_location) + "."};
    }

    if (
        first_location.shelf_index == second_location.shelf_index &&
        first_location.compartment_index == second_location.compartment_index
    )
    {
        return {false, "Cannot swap a compartment with itself."};
    }

    Compartment& first_compartment = get_compartment(first_location);
    Compartment& second_compartment = get_compartment(second_location);

    if (first_compartment.is_empty() || second_compartment.is_empty())
    {
        return {false, "Cannot swap items unless both compartments contain an item."};
    }

    first_compartment.swap_contents(second_compartment);
    return {
        true,
        "Items swapped successfully between " +
            format_location(first_location) +
            " and " +
            format_location(second_location) +
            "."
    };
}

void LibraryStorage::print_items_in_storage(std::ostream& output_stream) const
{
    bool found_checked_in_item = false;
    output_stream << "=== Items Currently Checked Into Storage ===\n";

    for (std::size_t shelf_index = 0; shelf_index < _shelves.size(); ++shelf_index)
    {
        const Shelf& shelf = _shelves[shelf_index];
        for (
            std::size_t compartment_index = 0;
            compartment_index < shelf.get_compartment_count();
            ++compartment_index
        )
        {
            const Compartment& compartment = shelf[compartment_index];
            if (!compartment.is_empty() && !compartment.is_checked_out())
            {
                found_checked_in_item = true;
                output_stream
                    << "Location: ["
                    << shelf_index
                    << "]["
                    << compartment_index
                    << "]\n"
                    << *compartment.get_item()
                    << "\n";
            }
        }
    }

    if (!found_checked_in_item)
    {
        output_stream << "No items are currently checked into storage.\n";
    }
}

void LibraryStorage::print_checked_out_items(std::ostream& output_stream) const
{
    bool found_checked_out_item = false;
    output_stream << "=== Items Currently Checked Out ===\n";

    for (std::size_t shelf_index = 0; shelf_index < _shelves.size(); ++shelf_index)
    {
        const Shelf& shelf = _shelves[shelf_index];
        for (
            std::size_t compartment_index = 0;
            compartment_index < shelf.get_compartment_count();
            ++compartment_index
        )
        {
            const Compartment& compartment = shelf[compartment_index];
            if (!compartment.is_empty() && compartment.is_checked_out())
            {
                found_checked_out_item = true;
                output_stream
                    << "Location: ["
                    << shelf_index
                    << "]["
                    << compartment_index
                    << "]\n"
                    << *compartment.get_item()
                    << "  Checked Out By : " << compartment.get_checked_out_by() << "\n"
                    << "  Due Date       : " << compartment.get_due_date() << "\n\n";
            }
        }
    }

    if (!found_checked_out_item)
    {
        output_stream << "No items are currently checked out.\n";
    }
}

bool LibraryStorage::is_valid_location(const CompartmentLocation& location) const
{
    if (location.shelf_index >= _shelves.size())
    {
        return false;
    }

    return location.compartment_index < Shelf::k_compartment_count;
}

std::string LibraryStorage::format_location(const CompartmentLocation& location) const
{
    return "[" + std::to_string(location.shelf_index) + "][" + std::to_string(location.compartment_index) + "]";
}

Compartment& LibraryStorage::get_compartment(const CompartmentLocation& location)
{
    return _shelves[location.shelf_index][location.compartment_index];
}

const Compartment& LibraryStorage::get_compartment(const CompartmentLocation& location) const
{
    return _shelves[location.shelf_index][location.compartment_index];
}
