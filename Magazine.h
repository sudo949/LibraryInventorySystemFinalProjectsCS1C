#ifndef MAGAZINE_H
#define MAGAZINE_H

#include "Item.h"
#include <string>


class Magazine : public Item {

public:
    Magazine(const std::string& name,
             const std::string& description,
             int id,
             int edition,
             const std::string& mainArticleTitle);

    int getEdition() const;
    std::string getMainArticleTitle() const;

    void print(std::ostream& os) const override;
    
    private:
    int edition;
    std::string mainArticleTitle;
};

#endif // MAGAZINE_H
