#ifndef BOOK_H
#define BOOK_H

#include "Item.h"
#include <string>


class Book : public Item {

public:
    Book(const std::string& name,
         const std::string& description,
         int id,
         const std::string& title,
         const std::string& author,
         int copyrightDate);

    std::string getTitle() const;
    std::string getAuthor() const;
    int getCopyrightDate() const;

    // implement your own print...
    void print(std::ostream& os) const override;
    
    private:
    std::string title;
    std::string author;
    int copyrightDate;

};

#endif // BOOK_H
