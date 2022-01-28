#ifndef Truck_hpp
#define Truck_hpp

#include <stdio.h>
#include "Vehicle.hpp"

class Truck : public Vehicle{
public:
    Truck();
    Truck(const char*, const char*, const char*, int, double, int);
    Truck(const Truck&);
    Truck& operator=(const Truck&);
    ~Truck();
    
    virtual void details() const override;
    
private:
    int size;
};
