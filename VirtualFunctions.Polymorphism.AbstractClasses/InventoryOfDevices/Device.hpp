#ifndef Device_hpp
#define Device_hpp

#include <stdio.h>
#include <iostream>
using namespace std;

class Device{
public:
    Device();
    Device(const char*);
    Device(const Device&);
    Device& operator=(const Device&);
    virtual ~Device();
    
    virtual void print() const;
    virtual int get_perf() const = 0;
    virtual Device* clone() = 0;
private:
    char* manufacturer;
    
    void copyDevice(const Device&);
};
#endif /* Device_hpp */
