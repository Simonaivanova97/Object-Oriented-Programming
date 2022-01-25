#ifndef Inventory_hpp
#define Inventory_hpp

#include <stdio.h>
#include "Laptop.hpp"
#include "Car.hpp"

class Inventory{
public:
    Inventory();
    Inventory(Device**, int, int);
    Inventory(const Inventory&);
    Inventory& operator=(const Inventory&);
    ~Inventory();

    void print() const;
    bool inAscendingOrder() const;
private:
    Device** arr;
    int numberOfDevices;
    int maxCapacity;
    
    void copyInventory(const Inventory&);
    void erase();
};

#endif /* Inventory_hpp */

