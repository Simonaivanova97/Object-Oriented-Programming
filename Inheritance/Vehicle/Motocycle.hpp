#ifndef Motocycle_hpp
#define Motocycle_hpp

#include <stdio.h>
#include "Vehicle.hpp"

class Motocycle : public Vehicle{
public:
    Motocycle();
    Motocycle(const char*, const char*, const char*, int, double, const char*);
    Motocycle(const Motocycle&);
    Motocycle& operator=(const Motocycle&);
    ~Motocycle();
    
    virtual void details() const override;
private:
    char* type;
    
    void copyMotocycle(const Motocycle&);
};

#endif /* Motocycle_hpp */
