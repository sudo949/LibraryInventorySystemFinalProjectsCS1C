#include "book_item.h"
#include "compartment_location.h"
#include "item_creator.h"
#include "library_storage.h"
#include "magazine_item.h"
#include "movie_item.h"

#include <iostream>
#include <stdexcept>
#include <string>
#include <vector>

void print_result(const std::string& action_name, const OperationResult& operation_result)
{
    std::cout
        << action_name
        << ": "
        << (operation_result.success ? "SUCCESS" : "FAILURE")
        << " - "
        << operation_result.message
        << "\n";
}

int main()
{
    LibraryStorage library_storage(3U);

    std::cout << "=== Add Items ===\n";
    print_result(
        "Add book to [0][0]",
        library_storage.add_item(
            ItemFactory::instance().create_item<Book>(
                "The Great Gatsby",
                "A novel set in the Jazz Age.",
                101,
                "The Great Gatsby",
                "F. Scott Fitzgerald",
                1925
            ),
            {0U, 0U}
        )
    );
    print_result(
        "Add movie to [1][5]",
        library_storage.add_item(
            ItemFactory::instance().create_item<Movie>(
                "Inception",
                "A mind-bending thriller.",
                202,
                "Inception",
                "Christopher Nolan",
                std::vector<std::string>{
                    "Leonardo DiCaprio",
                    "Joseph Gordon-Levitt",
                    "Elliot Page"
                }
            ),
            {1U, 5U}
        )
    );
    print_result(
        "Add magazine to [2][4]",
        library_storage.add_item(
            ItemFactory::instance().create_item<Magazine>(
                "National Geographic",
                "Science and nature magazine.",
                303,
                47,
                "The Last Ocean"
            ),
            {2U, 4U}
        )
    );
    print_result(
        "Add second book to [0][1]",
        library_storage.add_item(
            ItemFactory::instance().create_item<Book>(
                "Clean Code",
                "A book about writing maintainable software.",
                404,
                "Clean Code",
                "Robert C. Martin",
                2008
            ),
            {0U, 1U}
        )
    );
    print_result(
        "Add item to occupied [0][0]",
        library_storage.add_item(
            ItemFactory::instance().create_item<Book>(
                "The Great Gatsby",
                "A novel set in the Jazz Age.",
                101,
                "The Great Gatsby",
                "F. Scott Fitzgerald",
                1925
            ),
            {0U, 0U}
        )
    );
    print_result(
        "Add item to invalid [4][2]",
        library_storage.add_item(
            ItemFactory::instance().create_item<Book>(
                "The Great Gatsby",
                "A novel set in the Jazz Age.",
                101,
                "The Great Gatsby",
                "F. Scott Fitzgerald",
                1925
            ),
            {4U, 2U}
        )
    );

    std::cout << "\n=== Direct Access Demo ===\n";
    const Item* item_at_target_location = library_storage[2U][4U].get_item();
    if (item_at_target_location != nullptr)
    {
        std::cout << "Item at library_storage[2][4]:\n" << *item_at_target_location << "\n";
    }

    std::cout << "Attempting library_storage[9][0]...\n";
    try
    {
        library_storage[9U][0U];
        std::cout << "Unexpected success.\n";
    }
    catch (const std::out_of_range& exception)
    {
        std::cout << "Caught out_of_range: " << exception.what() << "\n";
    }

    std::cout << "\n=== Checkout Operations ===\n";
    print_result(
        "Checkout [2][4]",
        library_storage.check_out_item({2U, 4U}, "Alice Johnson", "2026-06-01")
    );
    print_result(
        "Checkout [2][4] again",
        library_storage.check_out_item({2U, 4U}, "Bob Smith", "2026-06-15")
    );
    print_result(
        "Checkout empty [2][10]",
        library_storage.check_out_item({2U, 10U}, "Charlie", "2026-06-20")
    );

    std::cout << "\n=== Storage Reports After Checkout ===\n";
    library_storage.print_items_in_storage(std::cout);
    std::cout << "\n";
    library_storage.print_checked_out_items(std::cout);

    std::cout << "\n=== Checkin Operations ===\n";
    print_result("Checkin [2][4]", library_storage.check_in_item({2U, 4U}));
    print_result("Checkin empty [2][10]", library_storage.check_in_item({2U, 10U}));
    print_result("Checkin already stored [2][4]", library_storage.check_in_item({2U, 4U}));

    std::cout << "\n=== Swap Operations ===\n";
    print_result("Swap [0][0] with [1][5]", library_storage.swap_items({0U, 0U}, {1U, 5U}));
    print_result("Swap [0][0] with empty [1][6]", library_storage.swap_items({0U, 0U}, {1U, 6U}));
    print_result("Swap [0][0] with itself", library_storage.swap_items({0U, 0U}, {0U, 0U}));

    std::cout << "\n=== Final Storage Reports ===\n";
    library_storage.print_items_in_storage(std::cout);
    std::cout << "\n";
    library_storage.print_checked_out_items(std::cout);

    return 0;
}
