#ifndef Garage_hpp
#define Garage_hpp

#include <stdio.h>
#include "Car.hpp"

class Garage{
public:
    Garage();
    Garage(const char*, int, int, const Car*);
    Garage(const Garage&);
    Garage& operator=(const Garage&);
    ~Garage();
    
    void addCar(const Car&);
    void removeCar(const char*);
    int getCurrentNmberOfCar() const;
    Car operator[](int);
    
    void print()const;
private:
    char* name;
    int currentNumberOfCar;
    int maxNumberOfCar;
    Car* arr;
    
    void copyGarage(const Garage&);
    bool containsCar(const char*) const;
};
#endif /* Garage_hpp */
