#ifndef Bookstore_hpp
#define Bookstore_hpp

#include <stdio.h>
#include "PrintEdition.hpp"
#include "Book.hpp"
#include "Magazine.hpp"
#include "Manga.hpp"

class Bookstore{
public:
    Bookstore();
    Bookstore(PrintEdition**, int, int);
    Bookstore(const Bookstore&);
    Bookstore& operator=(const Bookstore&);
    ~Bookstore();
    
    void print() const;
    void addPrintedition(PrintEdition*);
    const PrintEdition* operator[](const char*);
    int numberMangaWeekly() const;

private:
    PrintEdition** arr;
    int numberOfElement;
    int capacity;
    
    void copyBookstore(const Bookstore&);
    void erase();
};
