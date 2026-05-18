#ifndef LIBRARY_ITEM_H
#define LIBRARY_ITEM_H

#include <iosfwd>
#include <string>

class Item
{
public:
    Item(const std::string& name, const std::string& description, int id);
    virtual ~Item() = default;

    const std::string& get_name() const;
    const std::string& get_description() const;
    int get_id() const;

    virtual void print(std::ostream& output_stream) const = 0;

    friend std::ostream& operator<<(std::ostream& output_stream, const Item& item);

protected:
    std::string _name;
    std::string _description;
    int _id;
};

#endif // LIBRARY_ITEM_H
