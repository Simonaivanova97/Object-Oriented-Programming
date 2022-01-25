#include "Employee.hpp"
void Employee::copyEmployee(const Employee& other){
    numberOfExecuteTasks=other.numberOfExecuteTasks;
    successfullyCompletedTasks=other.successfullyCompletedTasks;
    name=new char[strlen(other.name)+1];
    assert(name!=NULL);
    strcpy(name, other.name);
}
Employee::Employee(){
    numberOfExecuteTasks=0;
    successfullyCompletedTasks=0;
    name=new char[strlen("Unknown")+1];
    assert(name!=NULL);
    strcpy(name, "Unknown");
}
Employee::Employee(const char* n, int nT, int sT){
    numberOfExecuteTasks=nT;
    successfullyCompletedTasks=sT;
    name=new char[strlen(n)+1];
    assert(name!=NULL);
    strcpy(name, n);
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
int Employee::getNumberOfExecuteTasks() const{
    return numberOfExecuteTasks;
}
