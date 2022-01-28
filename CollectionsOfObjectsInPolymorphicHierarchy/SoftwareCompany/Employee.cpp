#include "Employee.hpp"
void Employee::copyEmployee(const Employee& other){
    name=new char[strlen(other.name)+1];
    assert(name!=NULL);
    strcpy(name, other.name);
    experience=other.experience;
    salary=other.salary;
}
Employee::Employee(){
    name=new char[strlen("Unknown")+1];
    assert(name!=NULL);
    strcpy(name, "Unknown");
    experience=0;
    salary=0;
}
Employee::Employee(const char* n, int e, double s){
    name=new char[strlen(n)+1];
    assert(name!=NULL);
    strcpy(name, n);
    experience=e;
    salary=s;
}
Employee::Employee(const Employee& other){
    copyEmployee(other);
}
Employee& Employee::operator=(const Employee& other){
    if(this!=&other){
        delete []name;
        copyEmployee(other);
    }
    return *this;
}
Employee::~Employee(){
    delete []name;
}
const char* Employee::getName() const{
    return name;
}
int Employee::getExperience() const{
    return experience;
}
int Employee::getSalary() const{
    return salary;
}
void Employee::print() const{
    cout<<"Name: "<<name<<endl;
    cout<<"Experience: "<<experience<<endl;
    cout<<"Salary: "<<salary<<endl;
}
