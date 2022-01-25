#ifndef Expert_hpp
#define Expert_hpp

#include <stdio.h>
#include "Employee.hpp"

class Expert : public Employee{
public:
    Expert();
    Expert(const char*, int, int);
    virtual ~Expert();
    
    virtual void print() const override;
    virtual bool execute(const char*) override;
    virtual double successRate() const override;
    virtual Employee* clone() override;

    friend ostream& operator<<(ostream&, const Expert&);
private:
};
#endif /* Expert_hpp */
