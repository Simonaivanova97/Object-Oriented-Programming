#include "Student.hpp"
void Student::copyStudent(const Student& other){
    specialty=new char[strlen(other.specialty)+1];
    assert(specialty!=NULL);
    strcpy(specialty, other.specialty);
    grade=other.grade;
}
Student::Student() : Person(){
    specialty=new char[strlen("Unknown")+1];
    assert(specialty!=NULL);
    strcpy(specialty, "Unknown");
    grade=0;
}
Student::Student(const char* fN, const char* lN, int a, const char* s, double g) : Person(fN, lN, a){
    specialty=new char[strlen(s)+1];
    assert(specialty!=NULL);
    strcpy(specialty, s);
    grade=g;
}
Student::Student(const Student& other) : Person(other){
    copyStudent(other);
}
Student& Student::operator=(const Student& other){
    if(this!=&other){
        delete []specialty;
        Person::operator=(other);
        copyStudent(other);
    }
    return *this;
}
Student::~Student(){
    delete []specialty;
}
void Student::print()const {
    Person::print();
    cout<<"Specialty: "<<specialty<<endl;
    cout<<"Grade: "<<grade<<endl;
}

