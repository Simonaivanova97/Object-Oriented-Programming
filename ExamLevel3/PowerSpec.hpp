#ifndef PowerSpec_hpp
#define PowerSpec_hpp

#include <stdio.h>
#include <iostream>
using namespace std;
class PowerSpec{
public:
    PowerSpec();
    PowerSpec(const char*, int, int);
    
    const char* getACDC() const;
    int getVoltage() const;
    int getAmps() const;
    
    int getPower() const;
    bool operator==(const PowerSpec&) const;
    bool operator!=(const PowerSpec&) const;
    bool operator<(const PowerSpec&) const;
    bool operator>(const PowerSpec&) const;
    bool operator<=(const PowerSpec&) const;
    bool operator>=(const PowerSpec&) const;
    
    void print() const;
    
private:
    char ACDC[3];
    int voltage;
    int amps;
};

#endif /* PowerSpec_hpp */
