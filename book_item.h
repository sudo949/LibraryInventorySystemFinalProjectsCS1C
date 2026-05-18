#ifndef BOOK_ITEM_H
#define BOOK_ITEM_H

#include "library_item.h"

#include <string>

class Book : public Item
{
public:
    Book(
        const std::string& name,
        const std::string& description,
        int id,
        const std::string& title,
        const std::string& author,
        int copyright_date
    );

    const std::string& get_title() const;
    const std::string& get_author() const;
    int get_copyright_date() const;

    void print(std::ostream& output_stream) const override;

private:
    std::string _title;
    std::string _author;
    int _copyright_date;
};

#endif // BOOK_ITEM_H
