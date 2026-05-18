#include "magazine_item.h"

#include <ostream>

Magazine::Magazine(
    const std::string& name,
    const std::string& description,
    int id,
    int edition,
    const std::string& main_article_title
)
    : Item(name, description, id),
      _edition(edition),
      _main_article_title(main_article_title)
{
}

int Magazine::get_edition() const
{
    return _edition;
}

const std::string& Magazine::get_main_article_title() const
{
    return _main_article_title;
}

void Magazine::print(std::ostream& output_stream) const
{
    output_stream << "[MAGAZINE]\n"
                  << "  ID               : " << _id << "\n"
                  << "  Name             : " << _name << "\n"
                  << "  Edition          : " << _edition << "\n"
                  << "  MainArticleTitle : " << _main_article_title << "\n"
                  << "  Description      : " << _description << "\n";
}
