#ifndef Surgeon_hpp
#define Surgeon_hpp

#include <stdio.h>
#include "Nurse.hpp"
#include "Dentist.hpp"

class Surgeon : public Nurse, public Dentist{
public:
    Surgeon();
    Surgeon(const char*, int, int, int, const char*, int);
    Surgeon(const Surgeon&);
    Surgeon& operator=(const Surgeon&);
    virtual ~Surgeon();
    
    int getNumberOfOperations() const;
    virtual int getSalary() const override;
    virtual void print() const override;
    virtual Doctor* clone() override;

private:
    char* specialization;
    int numberOfOperations;
    
    void copySurgeon(const Surgeon&);
};

#endif /* Surgeon_hpp */

