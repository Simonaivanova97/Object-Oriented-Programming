#include "Vet.hpp"
void Vet::copyVet(const Vet& other){
    animal=new char[strlen(other.animal)+1];
    assert(animal!=NULL);
    strcpy(animal, other.animal);
}
Vet::Vet() : Doctor(){
    animal=new char[strlen("Unknown")+1];
    assert(animal!=NULL);
    strcpy(animal, "Unknown");
}
Vet::Vet(const char* n, int y, const char* a) : Doctor(n, y){
    animal=new char[strlen(a)+1];
    assert(animal!=NULL);
    strcpy(animal, a);
}
Vet::Vet(const Vet& other) : Doctor(other){
    copyVet(other);
}
Vet& Vet::operator=(const Vet& other){
    if(this!=&other){
        delete []animal;
        Doctor::operator=(other);
        copyVet(other);
    }
    return *this;
}
Vet::~Vet(){
    delete []animal;
}
double Vet::chance(const char* spec){
    if(strcmp(animal, spec)==0){
        return 50 + yearsOfExperience * (4/5);
    }
    else{
        return 45 + yearsOfExperience * (3/4);
    }
}
ostream& operator<<(ostream& os, const Vet& v){
    return os<<(Doctor&) v<<"Animal: "<<v.animal<<'\n';
}
