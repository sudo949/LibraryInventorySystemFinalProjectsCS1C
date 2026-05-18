#include "item_creator.h"

#include "book_item.h"
#include "magazine_item.h"
#include "movie_item.h"

#include <memory>

BookCreator::BookCreator(
    const std::string& name,
    const std::string& description,
    int id,
    const std::string& title,
    const std::string& author,
    int copyright_date
)
    : _name(name),
      _description(description),
      _id(id),
      _title(title),
      _author(author),
      _copyright_date(copyright_date)
{
}

std::unique_ptr<Item> BookCreator::create_item() const
{
    return std::make_unique<Book>(
        _name,
        _description,
        _id,
        _title,
        _author,
        _copyright_date
    );
}

MovieCreator::MovieCreator(
    const std::string& name,
    const std::string& description,
    int id,
    const std::string& title,
    const std::string& director,
    const std::vector<std::string>& main_actors
)
    : _name(name),
      _description(description),
      _id(id),
      _title(title),
      _director(director),
      _main_actors(main_actors)
{
}

std::unique_ptr<Item> MovieCreator::create_item() const
{
    return std::make_unique<Movie>(
        _name,
        _description,
        _id,
        _title,
        _director,
        _main_actors
    );
}

MagazineCreator::MagazineCreator(
    const std::string& name,
    const std::string& description,
    int id,
    int edition,
    const std::string& main_article_title
)
    : _name(name),
      _description(description),
      _id(id),
      _edition(edition),
      _main_article_title(main_article_title)
{
}

std::unique_ptr<Item> MagazineCreator::create_item() const
{
    return std::make_unique<Magazine>(
        _name,
        _description,
        _id,
        _edition,
        _main_article_title
    );
}
