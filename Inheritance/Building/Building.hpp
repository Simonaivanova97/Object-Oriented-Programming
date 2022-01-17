#ifndef Building_hpp
#define Building_hpp

#include <stdio.h>
#include <iostream>
using namespace std;

class Building{
public:
    Building();
    Building(int, double, const char*);
    Building(const Building&);
    Building& operator=(const Building&);
    ~Building();
    
    int getHeight() const;
    double getArea() const;
    const char* getAddress() const;
    
    void setHeight(int);
    void setArea(double);
    void setAddress(const char*);
    
    void print() const;
private:
    int height;
    double area;
    char* address;
    
    void copyBuilding(const Building&);
};

#endif /* Building_hpp */
