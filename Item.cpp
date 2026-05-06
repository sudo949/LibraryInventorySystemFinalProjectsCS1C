#include "Item.h"

// Constructor
Item::Item(const std::string& name, const std::string& description, int id)
: name(name), description(description), id(id) {}

// Simple Getters
std::string Item::getName()        const 
{
    return name; 
}
std::string Item::getDescription() const 
{ 
return description; 
}
int Item::getId() const 
{ 
 return id; 
}

// Because operator<< returns the stream, you can string together text, items, and other types in one statement. This is annoying to implement but makes it so you don't have to manually call print() function
// and is good for chaining.
std::ostream& operator<<(std::ostream& os, const Item& item) {
    item.print(os);
    return os;
}
