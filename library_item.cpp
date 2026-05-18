#include "library_item.h"

#include <ostream>

Item::Item(const std::string& name, const std::string& description, int id)
    : _name(name),
      _description(description),
      _id(id)
{
}

const std::string& Item::get_name() const
{
    return _name;
}

const std::string& Item::get_description() const
{
    return _description;
}

int Item::get_id() const
{
    return _id;
}

std::ostream& operator<<(std::ostream& output_stream, const Item& item)
{
    item.print(output_stream);
    return output_stream;
}
