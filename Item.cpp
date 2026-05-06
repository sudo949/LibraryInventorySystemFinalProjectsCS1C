#include "Item.h"

// ============================================================
//  Item — Base Class Implementations
// ============================================================

// Constructor: initializes the three shared fields
Item::Item(const std::string& name, const std::string& description, int id)
    : name(name), description(description), id(id) {}

// Getters
std::string Item::getName()        const { return name; }
std::string Item::getDescription() const { return description; }
int         Item::getId()          const { return id; }

// operator<< delegates to the virtual print() so the correct
// subclass version is called regardless of pointer/reference type
std::ostream& operator<<(std::ostream& os, const Item& item) {
    item.print(os);
    return os;
}
