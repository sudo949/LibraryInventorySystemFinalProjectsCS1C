#ifndef ITEM_CREATOR_H
#define ITEM_CREATOR_H

#include "library_item.h"

#include <memory>
#include <type_traits>
#include <utility>

class ItemFactory
{
public:
    static ItemFactory& instance()
    {
        static ItemFactory item_factory_instance;
        return item_factory_instance;
    }

    template <typename ItemType, typename... ConstructorArgs>
    std::unique_ptr<Item> create_item(ConstructorArgs&&... constructor_args) const
    {
        static_assert(
            std::is_base_of_v<Item, ItemType>,
            "ItemFactory can only create classes derived from Item."
        );

        return std::make_unique<ItemType>(std::forward<ConstructorArgs>(constructor_args)...);
    }

    ItemFactory(const ItemFactory&) = delete;
    ItemFactory& operator=(const ItemFactory&) = delete;

private:
    ItemFactory() = default;
};

#endif // ITEM_CREATOR_H
