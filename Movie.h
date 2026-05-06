#ifndef MOVIE_H
#define MOVIE_H

#include "Item.h"
#include <string>
#include <vector>

// ============================================================
//  Movie — derived from Item
//  Additional fields: title, director, mainActors (collection)
// ============================================================
class Movie : public Item {
private:
    std::string title;
    std::string director;
    std::vector<std::string> mainActors;

public:
    Movie(const std::string& name,
          const std::string& description,
          int id,
          const std::string& title,
          const std::string& director,
          const std::vector<std::string>& mainActors);

    std::string              getTitle()      const;
    std::string              getDirector()   const;
    std::vector<std::string> getMainActors() const;

    void print(std::ostream& os) const override;
};

#endif // MOVIE_H
