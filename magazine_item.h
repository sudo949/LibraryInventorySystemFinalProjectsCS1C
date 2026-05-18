#ifndef MAGAZINE_ITEM_H
#define MAGAZINE_ITEM_H

#include "library_item.h"

#include <string>

class Magazine : public Item
{
public:
    Magazine(
        const std::string& name,
        const std::string& description,
        int id,
        int edition,
        const std::string& main_article_title
    );

    int get_edition() const;
    const std::string& get_main_article_title() const;

    void print(std::ostream& output_stream) const override;

private:
    int _edition;
    std::string _main_article_title;
};

#endif // MAGAZINE_ITEM_H
