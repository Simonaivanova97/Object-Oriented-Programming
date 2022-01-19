#include "Truck.hpp"
Truck::Truck() : Vehicle(){
    size=0;
}
Truck::Truck(const char* m, const char* mod, const char* c, int y, double mil, int s) : Vehicle(m, mod, c, y, mil){
    size=s;
}
Truck::Truck(const Truck& other) : Vehicle(other){
    size=other.size;
}
Truck& Truck::operator=(const Truck& other){
    if(this!=&other){
        Vehicle::operator=(other);
        size=other.size;
    }
    return  *this;
}
Truck::~Truck(){}
void Truck::details() const{
    Vehicle::details();
    cout<<"Size: "<<size<<endl;
}
