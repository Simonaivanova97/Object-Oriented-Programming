#ifndef Manga_hpp
#define Manga_hpp

#include <stdio.h>
#include "Book.hpp"
#include "Magazine.hpp"

class Manga : public Book, public Magazine{
public:
    Manga();
    Manga(const char*, int, double, const char*, Periodicity);
    bool weeklyManga() const;
    
    virtual void print() const override;

};
#endif /* Manga_hpp */
