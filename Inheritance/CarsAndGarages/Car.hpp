#ifndef Car_hpp
#define Car_hpp

#include <stdio.h>
#include <iostream>
using namespace std;

class Car{
public:
    Car();
    Car(const char*, int, int);
    Car(const Car&);
    Car& operator=(const Car&);
    ~Car();
    
    const char* getModel() const;
    int getMaxSpeed() const;
    int getYear() const;
    const char* getSerialNumber() const;
    
    void print() const;
    void read();
    
    bool operator<(const Car&) const;
private:
    char* model;
    int maxSpeed;
    int year;
    char* serialNumber;
    
    int id;
    static int nextId;
    
    void copyCar(const Car&);
};

#endif /* Car_hpp */
