#include "movie_item.h"

#include <cstddef>
#include <ostream>

Movie::Movie(
    const std::string& name,
    const std::string& description,
    int id,
    const std::string& title,
    const std::string& director,
    const std::vector<std::string>& main_actors
)
    : Item(name, description, id),
      _title(title),
      _director(director),
      _main_actors(main_actors)
{
}

const std::string& Movie::get_title() const
{
    return _title;
}

const std::string& Movie::get_director() const
{
    return _director;
}

const std::vector<std::string>& Movie::get_main_actors() const
{
    return _main_actors;
}

void Movie::print(std::ostream& output_stream) const
{
    output_stream << "[MOVIE]\n"
                  << "  ID            : " << _id << "\n"
                  << "  Name          : " << _name << "\n"
                  << "  Title         : " << _title << "\n"
                  << "  Director      : " << _director << "\n"
                  << "  Description   : " << _description << "\n"
                  << "  MainActors    : ";

    for (std::size_t actor_index = 0; actor_index < _main_actors.size(); ++actor_index)
    {
        output_stream << _main_actors[actor_index];
        if (actor_index + 1U < _main_actors.size())
        {
            output_stream << ", ";
        }
    }

    output_stream << "\n";
}
