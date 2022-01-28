#ifndef Manga_hpp
#define Manga_hpp

#include <stdio.h>
#include "Book.hpp"
#include "Magazine.hpp"

class Manga : public Book, public Magazine{
public:
    Manga();
    Manga(const char*, int, double, const char*, Periodicity);
    virtual ~Manga();
    bool weeklyManga() const;
    
    virtual void print() const override;
    virtual PrintEdition* clone() override;

};
#endif /* Manga_hpp */
