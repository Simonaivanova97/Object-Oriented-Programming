#ifndef Manager_hpp
#define Manager_hpp

#include <stdio.h>
#include "Employee.hpp"

class Manager : public Employee{
public:
    Manager();
    Manager(const char*, int, double, int);
    virtual ~Manager();
    
    virtual void print() const override;
    virtual Employee* clone() override;

private:
    int numberOfSubordinates;
};

#endif /* Manager_hpp */
