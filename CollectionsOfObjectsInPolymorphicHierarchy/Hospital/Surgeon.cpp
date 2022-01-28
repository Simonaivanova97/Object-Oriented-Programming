#include "Surgeon.hpp"
void Surgeon::copySurgeon(const Surgeon& other){
    specialization=new char[strlen(other.specialization)+1];
    assert(specialization!=NULL);
    strcpy(specialization, other.specialization);
    numberOfOperations=other.numberOfOperations;
}
Surgeon::Surgeon() : Doctor(), Nurse(), Dentist(){
    specialization=new char[strlen("Unknown")+1];
    assert(specialization!=NULL);
    strcpy(specialization, "Unknown");
    numberOfOperations=0;
}
Surgeon::Surgeon(const char* n, int e, int nP, int nPE, const char* s, int nO) : Doctor(n, e), Nurse(n, e, nP), Dentist(n, e, nPE){
    specialization=new char[strlen(s)+1];
    assert(specialization!=NULL);
    strcpy(specialization, s);
    numberOfOperations=nO;
}
Surgeon::Surgeon(const Surgeon& other) : Doctor(other), Nurse(other), Dentist(other){
    copySurgeon(other);
}
Surgeon& Surgeon::operator=(const Surgeon& other) {
    if(this!=&other){
        delete []specialization;
        Doctor::operator=(other);
        Nurse::operator=(other);
        Dentist::operator=(other);
        copySurgeon(other);
    }
    return *this;
}
Surgeon::~Surgeon(){
    delete []specialization;
}
int Surgeon::getSalary() const{
    return numberOfOperations*3+1000;
}
void Surgeon::print() const{
    Nurse::print();
    Dentist::printOwnData();
    cout<<"Specialization: "<<specialization<<endl;
    cout<<"Number of operations: "<<numberOfOperations<<endl;
}
Doctor* Surgeon::clone(){
    return new Surgeon(*this);
}
int Surgeon::getNumberOfOperations() const{
    return numberOfOperations;
}
