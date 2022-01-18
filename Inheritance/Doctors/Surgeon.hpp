#ifndef Surgeon_hpp
#define Surgeon_hpp

#include <stdio.h>
#include "Doctor.hpp"

class Surgeon : public Doctor{
public:
    Surgeon();
    Surgeon(const char*, int, const char*);
    Surgeon(const Surgeon&);
    Surgeon& operator=(const Surgeon&);
    ~Surgeon();
    
    friend ostream& operator<<(ostream&, const Surgeon&);
    double chance(const char*);
private:
    char* specialization;
    
    void copySurgeon(const Surgeon&);
};

#endif /* Surgeon_hpp */

