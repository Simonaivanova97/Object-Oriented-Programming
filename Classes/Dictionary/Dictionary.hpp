//
//  Dictionary.hpp
//  Test1
//
//  Created by Simona Ivanova on 10.01.22.
//

#ifndef Dictionary_hpp
#define Dictionary_hpp

#include <stdio.h>
#include "CoupleWords.hpp"

class Dictionary{
public:
    Dictionary();
    Dictionary(int, const CoupleWords*);
    Dictionary(const Dictionary&);
    Dictionary& operator=(const Dictionary&);
    ~Dictionary();
    
    void print()const;
    void addCoupleWords(const CoupleWords&);
    void deleteCoupleWords(const CoupleWords&);
    const char* operator[](const char*);
private:
    CoupleWords* arr;
    int size;
    
    void copyDictionary(const Dictionary&);
};
#endif /* Dictionary_hpp */
