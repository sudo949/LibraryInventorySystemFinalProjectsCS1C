#ifndef ITEM_H
#define ITEM_H

#include <iostream>
#include <string>

// ============================================================
//  Item — Abstract base class for all library items
//  Shared fields: name, description, id
//  Derived classes (in their own files): Book, Movie, Magazine
// ============================================================
class Item {
protected:
    std::string name;
    std::string description;
    int id;

public:
    Item(const std::string& name, const std::string& description, int id);
    virtual ~Item() = default;

    std::string getName()        const;
    std::string getDescription() const;
    int         getId()          const;

    // Pure virtual — every subclass must implement its own display logic
    virtual void print(std::ostream& os) const = 0;

    // Delegates to virtual print() so << works for all item types
    friend std::ostream& operator<<(std::ostream& os, const Item& item);
};

#endif // ITEM_H
