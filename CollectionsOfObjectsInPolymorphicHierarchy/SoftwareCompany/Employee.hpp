#ifndef Employee_hpp
#define Employee_hpp

#include <stdio.h>
#include <iostream>
using namespace std;

class Employee{
public:
    Employee();
    Employee(const char*, int, double);
    Employee(const Employee&);
    Employee& operator=(const Employee&);
    virtual ~Employee();
    
    const char* getName() const;
    int getExperience() const;
    int getSalary() const;
    
    virtual void print() const;
    virtual Employee* clone() = 0;
private:
    char* name;
    int experience;
    double salary;
    
    void copyEmployee(const Employee&);
};

#endif /* Employee_hpp */

