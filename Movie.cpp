#include "Movie.h"

// ============================================================
//  Movie — Implementations
// ============================================================

// Constructor: passes shared fields up to Item, sets Movie-specific ones
Movie::Movie(const std::string& name,
             const std::string& description,
             int id,
             const std::string& title,
             const std::string& director,
             const std::vector<std::string>& mainActors)
    : Item(name, description, id),
      title(title),
      director(director),
      mainActors(mainActors) {}

// Getters
std::string              Movie::getTitle()      const { return title; }
std::string              Movie::getDirector()   const { return director; }
std::vector<std::string> Movie::getMainActors() const { return mainActors; }

// Outputs all Movie fields to the provided stream, including the actor list
void Movie::print(std::ostream& os) const {
    os << "[MOVIE]\n"
       << "  ID          : " << id          << "\n"
       << "  Name        : " << name        << "\n"
       << "  Title       : " << title       << "\n"
       << "  Director    : " << director    << "\n"
       << "  Description : " << description << "\n"
       << "  Main Actors : ";

    // Print each actor separated by commas
    for (size_t i = 0; i < mainActors.size(); ++i) {
        os << mainActors[i];
        if (i < mainActors.size() - 1) os << ", ";
    }
    os << "\n";
}
