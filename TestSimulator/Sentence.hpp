#ifndef Sentence_hpp
#define Sentence_hpp

#include <stdio.h>
#include <iostream>
using namespace std;

class Sentence{
public:
    Sentence();
    Sentence(const char*);
    Sentence(const Sentence&);
    Sentence& operator=(const Sentence&);
    ~Sentence();
    
    const char* getSentence() const;
    void setSentence(const string&);
    
    void print(ostream& os) const;
    void read(istream& is);
    
private:
    char* str;
    
    void copySentence(const Sentence&);
};
#endif /* Sentence_hpp */
