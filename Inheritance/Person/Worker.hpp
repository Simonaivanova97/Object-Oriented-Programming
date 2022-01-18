#ifndef Worker_hpp
#define Worker_hpp

#include <stdio.h>
#include "Person.hpp"

class Worker : public Person{
public:
    Worker();
    Worker(const char*, const char*, int, double, int);
    
    void print() const;
    double calculateSalary() const;
private:
    double salaryForHour;
    int hours;
    
};

#endif /* Worker_hpp */
