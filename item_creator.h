#ifndef ITEM_CREATOR_H
#define ITEM_CREATOR_H

#include "library_item.h"

#include <memory>
#include <string>
#include <vector>

class ItemCreator
{
public:
    virtual ~ItemCreator() = default;
    virtual std::unique_ptr<Item> create_item() const = 0;
};

class BookCreator : public ItemCreator
{
public:
    BookCreator(
        const std::string& name,
        const std::string& description,
        int id,
        const std::string& title,
        const std::string& author,
        int copyright_date
    );

    std::unique_ptr<Item> create_item() const override;

private:
    std::string _name;
    std::string _description;
    int _id;
    std::string _title;
    std::string _author;
    int _copyright_date;
};

class MovieCreator : public ItemCreator
{
public:
    MovieCreator(
        const std::string& name,
        const std::string& description,
        int id,
        const std::string& title,
        const std::string& director,
        const std::vector<std::string>& main_actors
    );

    std::unique_ptr<Item> create_item() const override;

private:
    std::string _name;
    std::string _description;
    int _id;
    std::string _title;
    std::string _director;
    std::vector<std::string> _main_actors;
};

class MagazineCreator : public ItemCreator
{
public:
    MagazineCreator(
        const std::string& name,
        const std::string& description,
        int id,
        int edition,
        const std::string& main_article_title
    );

    std::unique_ptr<Item> create_item() const override;

private:
    std::string _name;
    std::string _description;
    int _id;
    int _edition;
    std::string _main_article_title;
};

#endif // ITEM_CREATOR_H
