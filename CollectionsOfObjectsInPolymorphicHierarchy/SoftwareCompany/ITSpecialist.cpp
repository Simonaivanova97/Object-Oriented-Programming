#include "ITSpecialist.hpp"
void ITSpecialist::copyItSpecialist(const ITSpecialist& other){
    projectName=new char[strlen(other.projectName)+1];
    assert(projectName!=NULL);
    strcpy(projectName, other.projectName);
}
ITSpecialist::ITSpecialist() : Employee(){
    projectName=new char[strlen("Unknown")+1];
    assert(projectName!=NULL);
    strcpy(projectName, "Unknown");
}
ITSpecialist::ITSpecialist(const char* n, int e, double s, const char* pN) : Employee(n, e, s){
    projectName=new char[strlen(pN)+1];
    assert(projectName!=NULL);
    strcpy(projectName, pN);
}
ITSpecialist::ITSpecialist(const ITSpecialist& other) : Employee(other){
    copyItSpecialist(other);
}
ITSpecialist& ITSpecialist::operator=(const ITSpecialist& other){
    if(this!=&other){
        delete []projectName;
        Employee::operator=(other);
        copyItSpecialist(other);
    }
    return *this;
}
ITSpecialist::~ITSpecialist(){
    delete []projectName;
}
void ITSpecialist::print() const{
    Employee::print();
    cout<<"Project name: "<<projectName<<endl;
}
Employee* ITSpecialist::clone(){
    return new ITSpecialist(*this);
}
