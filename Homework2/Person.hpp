//
//  Person.hpp
//  HW2
//
//  Created by Simona Ivanova on 7.06.20.
//  Copyright © 2020 Simona Ivanova. All rights reserved.
//

#ifndef Person_hpp
#define Person_hpp
#include<iostream>
#include <stdio.h>
class Person{
public:
    Person();
    Person(const char*, int);
    Person(const Person&);
    Person& operator=(const Person&);
    ~Person();
    
    const char* getPersonName()const;
    int getInsuranceId() const;
    
    void setPersonName(const char*);
    void setInsuranceId(int);
    
private:
    char* person_name;
    int insurance_id;
    void doCopy(const char*,int);
};
#endif /* Person_hpp */
