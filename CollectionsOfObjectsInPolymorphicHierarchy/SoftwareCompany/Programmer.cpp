#include "Programmer.hpp"
void Programmer::copyProgrammer(const Programmer& other){
    programmingLanguage=new char[strlen(other.programmingLanguage)+1];
    assert(programmingLanguage!=NULL);
    strcpy(programmingLanguage, other.programmingLanguage);
}
Programmer::Programmer() : ITSpecialist(){
    programmingLanguage=new char[strlen("Unknown")+1];
    assert(programmingLanguage!=NULL);
    strcpy(programmingLanguage, "Unknown");
}
Programmer::Programmer(const char* n, int e, double s, const char* pN, const char* pL) : ITSpecialist(n, e, s, pN){
    programmingLanguage=new char[strlen(pL)+1];
    assert(programmingLanguage!=NULL);
    strcpy(programmingLanguage, pL);
}
Programmer::Programmer(const Programmer& other) : ITSpecialist(other){
    copyProgrammer(other);
}
Programmer& Programmer::operator=(const Programmer& other){
    if(this!=&other){
        delete []programmingLanguage;
        ITSpecialist::operator=(other);
        copyProgrammer(other);
    }
    return *this;
}
Programmer::~Programmer(){
    delete []programmingLanguage;
}
const char* Programmer::getProgrammingLanguage() const{
    return programmingLanguage;
}
void Programmer::print() const{
    ITSpecialist::print();
    cout<<"Project language: "<<programmingLanguage<<endl;
}
Employee* Programmer::clone(){
    return new Programmer(*this);
}
