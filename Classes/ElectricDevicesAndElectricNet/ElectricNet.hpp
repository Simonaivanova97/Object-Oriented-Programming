#ifndef ElectricNet_hpp
#define ElectricNet_hpp

#include <stdio.h>
#include "ElectricDevice.hpp"

class ElectricNet{
public:
    ElectricNet();
    ElectricNet(int);
    ElectricNet(const ElectricNet&);
    ElectricNet& operator=(const ElectricNet&);
    ~ElectricNet();
    
    void operator+=(const ElectricDevice&);
    ElectricNet& operator-=(const char*);
    ElectricDevice operator[](const char*);
    bool operator!()const;
    ElectricNet& operator++();
    
    void print() const;
private:
    ElectricDevice* arr;
    int numberOfDevice;
    int currentPower;
    int maxPower;
    
    void copyElectricNet(const ElectricNet&);
    bool containsDevice(const char*);
};

#endif /* ElectricNet_hpp */

