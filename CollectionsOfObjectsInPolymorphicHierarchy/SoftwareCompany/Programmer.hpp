#ifndef Programmer_hpp
#define Programmer_hpp

#include <stdio.h>
#include "ITSpecialist.hpp"

class Programmer : public ITSpecialist{
public:
    Programmer();
    Programmer(const char*, int, double, const char*, const char*);
    Programmer(const Programmer&);
    Programmer& operator=(const Programmer&);
    virtual ~Programmer();
    
    const char* getProgrammingLanguage() const;
    
    virtual void print() const override;
    virtual Employee* clone() override;
private:
    char* programmingLanguage;
    
    void copyProgrammer(const Programmer&);
};

#endif /* Programmer_hpp */
