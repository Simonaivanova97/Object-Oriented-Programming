#include "Nurse.hpp"
Nurse::Nurse() : Doctor(){
    numberOfPatients=0;
}
Nurse::Nurse(const char* n, int e, int nP) : Doctor(n, e){
    numberOfPatients=nP;
}
Nurse::~Nurse(){}
int Nurse::getSalary() const{
    return numberOfPatients*3+100;
}
void Nurse::print() const{
    Doctor::print();
    cout<<"Number of patients: "<<numberOfPatients<<endl;
}
Doctor* Nurse::clone(){
    return new Nurse(*this);
}
int Nurse::getNumberOfPatients() const{
    return numberOfPatients;
}

