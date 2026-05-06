#include "Book.h"

// Constructor: passes shared fields up to Item, sets Book-specific ones
Book::Book(const std::string& name,
           const std::string& description,
           int id,
           const std::string& title,
           const std::string& author,
           int copyrightDate)
// these are the Item base class unique attributes...
    : Item(name, description, id),
// these attributes belong to the book object.
      title(title),
      author(author),
      copyrightDate(copyrightDate) {}

// Getters
std::string Book::getTitle()         const { return title; }
std::string Book::getAuthor()        const { return author; }
int         Book::getCopyrightDate() const { return copyrightDate; }

// Outputs all Book fields to the provided stream
// Called automatically by operator<< in the base class
void Book::print(std::ostream& os) const {
    os << "[BOOK]\n"
       << "  ID          : " << id            << "\n"
       << "  Name        : " << name          << "\n"
       << "  Title       : " << title         << "\n"
       << "  Author      : " << author        << "\n"
       << "  Copyright   : " << copyrightDate << "\n"
       << "  Description : " << description   << "\n";
}
