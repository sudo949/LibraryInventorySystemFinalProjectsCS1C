#ifndef LIBRARY_COMPARTMENT_H
#define LIBRARY_COMPARTMENT_H

#include "library_item.h"
#include "operation_result.h"

#include <memory>
#include <string>

class Compartment
{
public:
    Compartment() = default;

    bool is_empty() const;
    bool is_checked_out() const;

    const Item* get_item() const;
    Item* get_item();

    const std::string& get_checked_out_by() const;
    const std::string& get_due_date() const;

    void set_item(std::unique_ptr<Item> item);
    OperationResult checkout_item(const std::string& person_name, const std::string& due_date);
    OperationResult checkin_item();
    void swap_contents(Compartment& other);

private:
    std::unique_ptr<Item> _item;
    bool _checked_out = false;
    std::string _checked_out_by;
    std::string _due_date;
};

#endif // LIBRARY_COMPARTMENT_H
