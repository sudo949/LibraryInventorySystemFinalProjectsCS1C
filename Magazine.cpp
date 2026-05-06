#include "Magazine.h"

// ============================================================
//  Magazine — Implementations
// ============================================================

// Constructor: passes shared fields up to Item, sets Magazine-specific ones
Magazine::Magazine(const std::string& name,
                   const std::string& description,
                   int id,
                   int edition,
                   const std::string& mainArticleTitle)
    : Item(name, description, id),
      edition(edition),
      mainArticleTitle(mainArticleTitle) {}

// Getters
int         Magazine::getEdition()          const { return edition; }
std::string Magazine::getMainArticleTitle() const { return mainArticleTitle; }

// Outputs all Magazine fields to the provided stream
void Magazine::print(std::ostream& os) const {
    os << "[MAGAZINE]\n"
       << "  ID            : " << id               << "\n"
       << "  Name          : " << name             << "\n"
       << "  Edition       : " << edition          << "\n"
       << "  Main Article  : " << mainArticleTitle << "\n"
       << "  Description   : " << description      << "\n";
}
