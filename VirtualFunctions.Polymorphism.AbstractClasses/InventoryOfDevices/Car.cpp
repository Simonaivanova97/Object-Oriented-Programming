#include "Car.hpp"
Car::Car() : Device(){
    power=0;
    capacity=0;
}
Car::Car(const char* m, int p, int c) : Device(m){
    power=p;
    capacity=c;
}
Car::~Car(){}
void Car::print() const{
    Device::print();
    cout<<"Power: "<<power<<endl;
    cout<<"Capacity: "<<capacity<<endl;
}
int Car::get_perf() const{
    return power;
}
Device* Car::clone(){
    return new Car(*this);
}

