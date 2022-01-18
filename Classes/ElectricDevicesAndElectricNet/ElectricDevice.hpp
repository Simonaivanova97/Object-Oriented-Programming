#ifndef ElectricDevice_hpp
#define ElectricDevice_hpp

#include <stdio.h>
#include <iostream>
using  namespace std;

class ElectricDevice{
public:
    ElectricDevice();
    ElectricDevice(const char*, int);
    ElectricDevice(const ElectricDevice&);
    ElectricDevice& operator=(const ElectricDevice&);
    ~ElectricDevice();
    
    const char* getnameOfDevice() const;
    int getElectricPower() const;
    
    void print() const;
private:
    char* nameOfDevice;
    int electricPower;
    
    void copyElectricDevice(const ElectricDevice&);
};

#endif /* ElectricDevice_hpp */
