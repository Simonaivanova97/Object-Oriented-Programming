//
//  Company.hpp
//  Date
//
//  Created by Simona Ivanova on 12.09.21.
//

#ifndef Company_hpp
#define Company_hpp

#include <stdio.h>
#include "Employee.hpp"
const int maxCompanyName=51;

class Company{
public:
    Company();
    void appointsNewEmployee(const Employee&);
    void laysOffEmployee(const char*);
    void print()const;
    
    double budget()const;
    void increasesSalaries();
    
private:
    char companyName[maxCompanyName];
    Employee arr[150];
    int currentNumberEmployee;
    
    bool hasThisEmployee(const char*);
};

#endif /* Company_hpp */
