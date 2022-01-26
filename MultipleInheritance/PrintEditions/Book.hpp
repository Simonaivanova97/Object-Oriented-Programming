#ifndef Book_hpp
#define Book_hpp

#include <stdio.h>
#include "PrintEdition.hpp"

class Book : virtual public PrintEdition{
public:
    Book();
    Book(const char*, int, double, const char*);
    Book(const Book&);
    Book& operator=(const Book&);
    ~Book();
    
    void print() const;

private:
    char* author;
    
    void copyBook(const Book&);
};
#endif /* Book_hpp */
