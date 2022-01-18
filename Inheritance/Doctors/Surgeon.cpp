#include "Surgeon.hpp"
void Surgeon::copySurgeon(const Surgeon& other){
    specialization=new char[strlen(other.specialization)+1];
    assert(specialization!=NULL);
    strcpy(specialization, other.specialization);
}
Surgeon::Surgeon() : Doctor(){
    specialization=new char[strlen("Unknown")+1];
    assert(specialization!=NULL);
    strcpy(specialization, "Unknown");
}
Surgeon::Surgeon(const char* n, int y, const char* s) : Doctor(n, y){
    specialization=new char[strlen(s)+1];
    assert(specialization!=NULL);
    strcpy(specialization, s);
}
Surgeon::Surgeon(const Surgeon& other) : Doctor(other){
    copySurgeon(other);
}
Surgeon& Surgeon::operator=(const Surgeon& other){
    if(this!=&other){
        delete []specialization;
        Doctor::operator=(other);
        copySurgeon(other);
    }
    return *this;
}
Surgeon::~Surgeon(){
    delete []specialization;
}
double Surgeon::chance(const char* spec){
    if(strcmp(specialization, spec)==0){
        return 60 + yearsOfExperience;
    }
    else{
        return 40 + yearsOfExperience * (2/3);
    }
}
ostream& operator<<(ostream& os, const Surgeon& s){
    return os << (Doctor&) s<<"Specialization: "<<s.specialization<<'\n';
}
