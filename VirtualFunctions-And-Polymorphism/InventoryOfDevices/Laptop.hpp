#ifndef Laptop_hpp
#define Laptop_hpp

#include <stdio.h>
#include "Device.hpp"

class Laptop : public Device{
public:
    Laptop();
    Laptop(const char*, int);
    virtual ~Laptop();
    
    virtual void print() const override;
    virtual int get_perf() const override;
    virtual Device* clone() override;

private:
    int megaherz;
};
#endif /* Laptop_hpp */

