#ifndef MAGAZINE_H
#define MAGAZINE_H

#include "Item.h"
#include <string>

// ============================================================
//  Magazine — derived from Item
//  Additional fields: edition, mainArticleTitle
// ============================================================
class Magazine : public Item {
private:
    int edition;
    std::string mainArticleTitle;

public:
    Magazine(const std::string& name,
             const std::string& description,
             int id,
             int edition,
             const std::string& mainArticleTitle);

    int         getEdition()          const;
    std::string getMainArticleTitle() const;

    void print(std::ostream& os) const override;
};

#endif // MAGAZINE_H
