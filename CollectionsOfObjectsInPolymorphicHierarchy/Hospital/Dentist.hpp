#ifndef Dentist_hpp
#define Dentist_hpp

#include <stdio.h>
#include "Doctor.hpp"
class Dentist : virtual public Doctor{
public:
    Dentist();
    Dentist(const char*, int, int);
    virtual ~Dentist();
    
    int getNumberOfPatientsExamined() const;
    
    virtual int getSalary() const override;
    virtual void print() const override;
    virtual Doctor* clone() override;

private:
    int numberOfPatientsExamined;
    
protected:
    void printOwnData() const;
};

#endif /* Dentist_hpp */

