#ifndef MOVIE_ITEM_H
#define MOVIE_ITEM_H

#include "library_item.h"

#include <string>
#include <vector>

class Movie : public Item
{
public:
    Movie(
        const std::string& name,
        const std::string& description,
        int id,
        const std::string& title,
        const std::string& director,
        const std::vector<std::string>& main_actors
    );

    const std::string& get_title() const;
    const std::string& get_director() const;
    const std::vector<std::string>& get_main_actors() const;

    void print(std::ostream& output_stream) const override;

private:
    std::string _title;
    std::string _director;
    std::vector<std::string> _main_actors;
};

#endif // MOVIE_ITEM_H
