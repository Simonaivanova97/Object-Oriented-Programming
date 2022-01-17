#ifndef House_hpp
#define House_hpp

#include <stdio.h>
#include "Building.hpp"

class House : public Building{
public:
    House();
    House(int, double, const char*, int, const char*);
    House(const House&);
    House& operator=(const House&);
    ~House();
    
    int getNumberOfFloors() const;
    const char* getOwnerName() const;
    
    void setNumberOfFloors(int);
    void setOwnerName(const char*);
    
    void print() const;
private:
    int numberOfFloors;
    char* ownerName;
    
    void copyHouse(const House&);
};

#endif /* House_hpp */
