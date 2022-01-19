#include "Motocycle.hpp"
void Motocycle::copyMotocycle(const Motocycle& other){
    type=new char[strlen(other.type)+1];
    assert(type!=NULL);
    strcpy(type, other.type);
}
Motocycle::Motocycle() : Vehicle(){
    type=new char[strlen("Unknown")+1];
    assert(type!=NULL);
    strcpy(type, "Unknown");
}
Motocycle::Motocycle(const char* m, const char* mod, const char* c, int y, double mil, const char* t) : Vehicle(m, mod, c, y, mil){
    type=new char[strlen(t)+1];
    assert(type!=NULL);
    strcpy(type, t);
}
Motocycle::Motocycle(const Motocycle& other) : Vehicle(other){
    copyMotocycle(other);
}
Motocycle& Motocycle::operator=(const Motocycle& other){
    if(this!=&other){
        delete []type;
        Vehicle::operator=(other);
        copyMotocycle(other);
    }
    return *this;
}
Motocycle::~Motocycle(){
    delete []type;
}
void Motocycle::details() const{
    Vehicle::details();
    cout<<"Type: "<<type<<endl;
}
