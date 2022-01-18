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
    ~Doctor();
    
    friend ostream& operator<<(ostream&, const Doctor&);
protected:
    char* name;
    int yearsOfExperience;
    
    void copyDoctor(const Doctor&);
};

#endif /* Doctor_hpp */
