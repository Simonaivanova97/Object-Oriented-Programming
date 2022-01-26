#ifndef PrintEdition_hpp
#define PrintEdition_hpp

#include <stdio.h>
#include <iostream>
using namespace std;

class PrintEdition{
public:
    PrintEdition();
    PrintEdition(const char*, int, double);
    PrintEdition(const PrintEdition&);
    PrintEdition& operator=(const PrintEdition&);
    ~PrintEdition();
    
    const char* getTitile() const;
    void print() const;

private:
    char* title;
    int year;
    double price;
    
    void copyPrintEdition(const PrintEdition&);
};
#endif /* PrintEdition_hpp */

