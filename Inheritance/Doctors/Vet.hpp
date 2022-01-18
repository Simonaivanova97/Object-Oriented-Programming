#ifndef Vet_hpp
#define Vet_hpp

#include <stdio.h>
#include "Doctor.hpp"
class Vet : public Doctor{
public:
    Vet();
    Vet(const char*, int, const char*);
    Vet(const Vet&);
    Vet& operator=(const Vet&);
    ~Vet();
    
    friend ostream& operator<<(ostream&, const Vet&);
    double chance(const char*);
private:
    char* animal;
    
    void copyVet(const Vet&);
};

#endif /* Vet_hpp */
