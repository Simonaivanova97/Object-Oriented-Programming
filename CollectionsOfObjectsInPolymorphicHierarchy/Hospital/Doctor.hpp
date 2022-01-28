#ifndef Doctor_hpp
#define Doctor_hpp

#include <stdio.h>
#include <iostream>
using namespace std;

class Doctor{
public:
    Doctor();
    Doctor(const char*, int);
    Doctor(const Doctor&);
    Doctor& operator=(const Doctor&);
    virtual ~Doctor();
    
    virtual int getSalary() const;
    virtual void print() const;
    virtual Doctor* clone() = 0;
private:
    char* name;
    int experience;
    
    void copyDoctor(const Doctor&);
};
#endif /* Doctor_hpp */
