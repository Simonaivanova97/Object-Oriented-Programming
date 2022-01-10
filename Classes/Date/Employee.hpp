//
//  Employee.hpp
//  Date
//
//  Created by Simona Ivanova on 12.09.21.
//

#ifndef Employee_hpp
#define Employee_hpp

#include <stdio.h>
#include "Date.hpp"
const int maxName=51;
const int maxPosition=21;

class Employee{
public:
    Employee();
    Employee(const char*,const Date&,const char*,double);
    
    const char* getName()const;
    Date getDate()const;
    const char* getPosition()const;
    double getSalary()const;
    
    void setName(const char*);
    void setDate(const Date&);
    void setPosition(const char*);
    void setSalary(double);
    
    void print() const;
private:
    char name[maxName];
    Date dateОfАppointment;
    char position[maxPosition];
    double salary;
    
    bool validSalary(double) const;
};

#endif /* Employee_hpp */
