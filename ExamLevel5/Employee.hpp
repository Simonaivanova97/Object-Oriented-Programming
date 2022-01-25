#ifndef Employee_hpp
#define Employee_hpp

#include <stdio.h>
#include <iostream>
using namespace std;

class Employee{
public:
    Employee();
    Employee(const char*, int, int);
    Employee(const Employee&);
    Employee& operator=(const Employee&);
    virtual ~Employee();
    
    const char* getName() const;
    int getNumberOfExecuteTasks() const;
    
    virtual bool execute(const char*) = 0;
    virtual double successRate() const = 0;
    virtual Employee* clone() = 0;
    virtual void print() const = 0;

private:
    char* name;
    
    void copyEmployee(const Employee&);
protected:
    int numberOfExecuteTasks;
    int successfullyCompletedTasks;
};

#endif /* Employee_hpp */
