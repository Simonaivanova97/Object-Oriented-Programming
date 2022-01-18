#include "Doctor.hpp"
void Doctor::copyDoctor(const Doctor& other){
    name=new char[strlen(other.name)+1];
    assert(name!=NULL);
    strcpy(name, other.name);
    yearsOfExperience=other.yearsOfExperience;
}
Doctor::Doctor(){
    name=new char[strlen("Unknown")+1];
    assert(name!=NULL);
    strcpy(name, "Unknown");
    yearsOfExperience=0;
}
Doctor::Doctor(const char* n, int y){
    name=new char[strlen(n)+1];
    assert(name!=NULL);
    strcpy(name, n);
    yearsOfExperience=y;
}
Doctor::Doctor(const Doctor& other){
    copyDoctor(other);
}
Doctor& Doctor::operator=(const Doctor& other){
    if(this!=&other){
        delete []name;
        copyDoctor(other);
    }
    return *this;
}
Doctor::~Doctor(){
    delete []name;
}
ostream& operator<<(ostream& os, const Doctor& d){
    return os<<"Name: "<<d.name<<"\nExperience: "<<d.yearsOfExperience<<'\n';
}
