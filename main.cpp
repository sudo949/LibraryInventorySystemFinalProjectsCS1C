#include <iostream>
#include "Item.h"
#include "Book.h"
#include "Movie.h"
#include "Magazine.h"
#include "Compartment.h"

// ============================================================
//  Part 1 Test Driver
//  Demonstrates construction and << output for all three item types.
//  Also shows polymorphism via base class pointer (Item*).
// ============================================================
int main() {

    // --- Construct a Book ---
    Book book(
        "The Great Gatsby",                          // name
        "A novel set in the Jazz Age",               // description
        101,                                         // id
        "The Great Gatsby",                          // title
        "F. Scott Fitzgerald",                       // author
        1925                                         // copyrightDate
    );

    // --- Construct a Movie ---
    Movie movie(
        "Inception",                                 // name
        "A mind-bending thriller",                   // description
        202,                                         // id
        "Inception",                                 // title
        "Christopher Nolan",                         // director
        {"Leonardo DiCaprio", "Joseph Gordon-Levitt", "Elliot Page"} // mainActors
    );

    // --- Construct a Magazine ---
    Magazine magazine(
        "National Geographic",                       // name
        "Science and nature magazine",               // description
        303,                                         // id
        47,                                          // edition
        "The Last Ocean"                             // mainArticleTitle
    );

    std::cout << "=== Direct Object Output via << ===\n\n";

    // operator<< calls print() on each concrete type directly
    std::cout << book     << "\n";
    std::cout << movie    << "\n";
    std::cout << magazine << "\n";

    // --- Polymorphism Demo ---
    // Store all three items as base class pointers.
    // operator<< still dispatches to the correct print() override
    // because print() is virtual — this is runtime polymorphism.
    std::cout << "=== Polymorphic Output via Item* ===\n\n";

    Item* items[] = { &book, &movie, &magazine };

    for (const Item* item : items) {
        std::cout << *item << "\n";
    }

    return 0;
}
