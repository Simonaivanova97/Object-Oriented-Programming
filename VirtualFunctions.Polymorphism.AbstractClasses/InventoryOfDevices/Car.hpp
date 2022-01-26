#ifndef Car_hpp
#define Car_hpp

#include <stdio.h>
#include "Device.hpp"

class Car : public Device{
public:
    Car();
    Car(const char*, int, int);
    virtual ~Car();
    
    virtual void print() const override;
    virtual int get_perf() const override;
    virtual Device* clone() override;

private:
    int power;
    int capacity;
};

#endif /* Car_hpp */

