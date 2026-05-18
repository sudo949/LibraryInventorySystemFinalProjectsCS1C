#include "library_compartment.h"

#include <memory>
#include <utility>

bool Compartment::is_empty() const
{
    return _item == nullptr;
}

bool Compartment::is_checked_out() const
{
    return _checked_out;
}

const Item* Compartment::get_item() const
{
    return _item.get();
}

Item* Compartment::get_item()
{
    return _item.get();
}

const std::string& Compartment::get_checked_out_by() const
{
    return _checked_out_by;
}

const std::string& Compartment::get_due_date() const
{
    return _due_date;
}

void Compartment::set_item(std::unique_ptr<Item> item)
{
    _item = std::move(item);
    _checked_out = false;
    _checked_out_by.clear();
    _due_date.clear();
}

OperationResult Compartment::checkout_item(const std::string& person_name, const std::string& due_date)
{
    if (is_empty())
    {
        return {false, "Cannot check out an item from an empty compartment."};
    }

    if (_checked_out)
    {
        return {false, "Cannot check out an item that is already checked out."};
    }

    if (person_name.empty())
    {
        return {false, "Cannot check out an item without a borrower name."};
    }

    if (due_date.empty())
    {
        return {false, "Cannot check out an item without a due date."};
    }

    _checked_out = true;
    _checked_out_by = person_name;
    _due_date = due_date;
    return {true, "Item checked out successfully."};
}

OperationResult Compartment::checkin_item()
{
    if (is_empty())
    {
        return {false, "Cannot check in an item from an empty compartment."};
    }

    if (!_checked_out)
    {
        return {false, "Cannot check in an item that is already in storage."};
    }

    _checked_out = false;
    _checked_out_by.clear();
    _due_date.clear();
    return {true, "Item checked in successfully."};
}

void Compartment::swap_contents(Compartment& other)
{
    _item.swap(other._item);
    std::swap(_checked_out, other._checked_out);
    std::swap(_checked_out_by, other._checked_out_by);
    std::swap(_due_date, other._due_date);
}
