#ifndef Company_hpp
#define Company_hpp

#include <stdio.h>
#include "Employee.hpp"
#include "ITSpecialist.hpp"
#include "Programmer.hpp"
#include "QA.hpp"
#include "Manager.hpp"

class Company{
public:
    Company();
    Company(int);
    Company(const Company&);
    Company& operator=(const Company&);
    ~Company();
    
    void print() const;
    void addEmployee(Employee*);
    void removeEmployee(const char*);
    void removeNewEmployee();
    double sumSalaries() const;
    double avgSalary() const;
    void removeHTMLProgrammer();
    
private:
    Employee** arr;
    int numberOfEmployees;
    int maxCapacity;
    
    void copyCompany(const Company&);
    void erase();
    void resize();
    bool containsEmployee(const char*);
};

#endif /* Company_hpp */
