#include "Car.hpp"
Car::Car() : Vehicle(){}
Car::Car(const char* m, const char* mod, const char* c, int y, double mil) : Vehicle(m, mod, c, y, mil) {}
Car::Car(const Car& other) : Vehicle(other){}
Car& Car::operator=(const Car& other){
    if(this!=&other){
        Vehicle::operator=(other);
    }
    return *this;
}
Car::~Car(){}
void Car::details() const{
    Vehicle::details();
}
