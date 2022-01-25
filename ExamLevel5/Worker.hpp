#ifndef Worker_hpp
#define Worker_hpp

#include <stdio.h>
#include "Employee.hpp"

class Worker : public Employee{
public:
    Worker();
    Worker(const char*, int, int, int);
    virtual ~Worker();
    
    virtual bool execute(const char*) override;
    virtual double successRate() const override;
    virtual Employee* clone() override;
    
    virtual void print() const override;
    friend ostream& operator<<(ostream&, const Worker&);
private:
    int k;
    int currentExecuteTasks;
    
};
