//
//  CoupleWords.hpp
//  Test1
//
//  Created by Simona Ivanova on 10.01.22.
//

#ifndef CoupleWords_hpp
#define CoupleWords_hpp

#include <stdio.h>
#include <iostream>
#include <iomanip>
using namespace std;

class CoupleWords{
public:
    CoupleWords();
    CoupleWords(const char*, const char*);
    CoupleWords(const CoupleWords&);
    CoupleWords& operator=(const CoupleWords&);
    ~CoupleWords();
    
    const char* getWord() const;
    const char* getMeaning() const;
    
    void setWord(const char*);
    void setMeaning(const char*);
    
    void print() const;
private:
    char* word;
    char* meaning;
    
    void copyCoupleWords(const CoupleWords&);
};

#endif /* CoupleWords_hpp */
