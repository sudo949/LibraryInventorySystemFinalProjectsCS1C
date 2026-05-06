#ifndef BOOK_H
#define BOOK_H

#include "Item.h"
#include <string>

// ============================================================
//  Book — derived from Item
//  Additional fields: title, author, copyrightDate
// ============================================================
class Book : public Item {
private:
    std::string title;
    std::string author;
    int copyrightDate;

public:
    Book(const std::string& name,
         const std::string& description,
         int id,
         const std::string& title,
         const std::string& author,
         int copyrightDate);

    std::string getTitle()         const;
    std::string getAuthor()        const;
    int         getCopyrightDate() const;

    void print(std::ostream& os) const override;
};

#endif // BOOK_H
