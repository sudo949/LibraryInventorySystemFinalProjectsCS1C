#include "book_item.h"

#include <ostream>

Book::Book(
    const std::string& name,
    const std::string& description,
    int id,
    const std::string& title,
    const std::string& author,
    int copyright_date
)
    : Item(name, description, id),
      _title(title),
      _author(author),
      _copyright_date(copyright_date)
{
}

const std::string& Book::get_title() const
{
    return _title;
}

const std::string& Book::get_author() const
{
    return _author;
}

int Book::get_copyright_date() const
{
    return _copyright_date;
}

void Book::print(std::ostream& output_stream) const
{
    output_stream << "[BOOK]\n"
                  << "  ID            : " << _id << "\n"
                  << "  Name          : " << _name << "\n"
                  << "  Title         : " << _title << "\n"
                  << "  Author        : " << _author << "\n"
                  << "  CopyrightDate : " << _copyright_date << "\n"
                  << "  Description   : " << _description << "\n";
}
