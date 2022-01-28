#include "Dentist.hpp"
Dentist::Dentist() : Doctor(){
    numberOfPatientsExamined=0;
}
Dentist::Dentist(const char* n, int e, int nP) : Doctor(n, e){
    numberOfPatientsExamined=nP;
}
Dentist::~Dentist(){}
int Dentist::getNumberOfPatientsExamined() const{
    return numberOfPatientsExamined;
}
int Dentist::getSalary() const{
    return numberOfPatientsExamined+200;
}
void Dentist::print() const{
    Doctor::print();
    cout<<"Number of patients examined: "<<numberOfPatientsExamined<<endl;
}
void Dentist::printOwnData() const{
    cout<<"Number of patients examined: "<<numberOfPatientsExamined<<endl;
}
Doctor* Dentist::clone(){
    return new Dentist(*this);
}

