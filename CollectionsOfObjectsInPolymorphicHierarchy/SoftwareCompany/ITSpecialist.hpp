#ifndef ITSpecialist_hpp
#define ITSpecialist_hpp

#include <stdio.h>
#include "Employee.hpp"

class ITSpecialist : public Employee{
public:
    ITSpecialist();
    ITSpecialist(const char*, int, double, const char*);
    ITSpecialist(const ITSpecialist&);
    ITSpecialist& operator=(const ITSpecialist&);
    virtual ~ITSpecialist();
    
    virtual void print() const override;
    virtual Employee* clone() override;
private:
    char* projectName;
    
    void copyItSpecialist(const ITSpecialist&);
};

#endif /* ITSpecialist_hpp */
