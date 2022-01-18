#ifndef Student_hpp
#define Student_hpp

#include <stdio.h>
#include "Person.hpp"

class Student : public Person{
public:
    Student();
    Student(const char*, const char*, int, const char*, double);
    Student(const Student&);
    Student& operator=(const Student&);
    ~Student();
    
    void print()const;
private:
    char* specialty;
    double grade;
    
    void copyStudent(const Student&);
};

#endif /* Student_hpp */

