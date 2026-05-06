#ifndef ITEM_H
#define ITEM_H

#include <iostream>
#include <string>

class Item {

public:
    Item(const std::string& name, const std::string& description, int id);
    
    virtual ~Item() = default;

    std::string getName()        const;
    
    std::string getDescription() const;
    
    int getId() const;

    // Pure virtual function, implement your own logic.
    virtual void print(std::ostream& os) const = 0;

    // << operator will work for all item types, good for chaining.
    friend std::ostream& operator<<(std::ostream& os, const Item& item);

    protected:
    std::string name;
    std::string description;
    int id;
};

#endif // ITEM_H
