#ifndef Car_hpp
#define Car_hpp

#include <stdio.h>
#include "Vehicle.hpp"

class Car : public Vehicle{
public:
    Car();
    Car(const char*, const char*, const char*, int, double);
    Car(const Car&);
    Car& operator=(const Car&);
    virtual ~Car();
    
    virtual void details() const override;
};

#endif /* Car_hpp */
