#ifndef Nurse_hpp
#define Nurse_hpp

#include <stdio.h>
#include "Doctor.hpp"

class Nurse : virtual public Doctor{
public:
    Nurse();
    Nurse(const char*, int, int);
    virtual ~Nurse();
    
    int getNumberOfPatients() const;
    virtual int getSalary() const override;
    virtual void print() const override;
    virtual Doctor* clone() override;

private:
    int numberOfPatients;
    
};
#endif /* Nurse_hpp */
