#include "Laptop.hpp"
Laptop::Laptop() : Device(){
    megaherz=0;
}
Laptop::Laptop(const char* m, int mg) : Device(m){
    megaherz=mg;
}
Laptop::~Laptop(){}
void Laptop::print() const{
    Device::print();
    cout<<"Megaherz: "<<megaherz<<endl;
}
int Laptop::get_perf() const{
    return megaherz;
}
Device* Laptop::clone(){
    return new Laptop(*this);
}

