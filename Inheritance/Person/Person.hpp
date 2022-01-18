#ifndef Person_hpp
#define Person_hpp

#include <stdio.h>
#include <iostream>
using namespace std;

class Person{
public:
    Person();
    Person(const char*, const char*, int);
    Person(const Person&);
    Person& operator=(const Person&);
    ~Person();
    
    void print() const;
private:
    char* forename;
    char* lastname;
    int age;
    
    void copyPerson(const Person&);
};
