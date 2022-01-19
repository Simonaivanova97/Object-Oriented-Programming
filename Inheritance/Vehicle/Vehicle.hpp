#ifndef Vehicle_hpp
#define Vehicle_hpp

#include <stdio.h>
#include <iostream>
using namespace std;

class Vehicle{
public:
    Vehicle();
    Vehicle(const char*, const char*, const char*, int, double);
    Vehicle(const Vehicle&);
    Vehicle& operator=(const Vehicle&);
    virtual ~Vehicle();
    
    const char* getMake() const;
    const char* getModel() const;
    const char* getColor() const;
    int getYear() const;
    double getMileage() const;
    
    void setMake(const char*);
    void setModel(const char*);
    void setColor(const char*);
    void setYear(int);
    void setMileage(double);
    
    virtual void details() const = 0;
private:
    char* make;
    char* model;
    char* color;
    int year;
    double mileage;
    
    void copyVehicle(const Vehicle&);
};
#endif /* Vehicle_hpp */
