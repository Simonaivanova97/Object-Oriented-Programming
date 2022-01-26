#ifndef Ticket_hpp
#define Ticket_hpp

#include <stdio.h>
#include <iostream>
using namespace std;

class Ticket{
public:
    Ticket();
    Ticket(const char*, double);
    Ticket(const Ticket&);
    Ticket& operator=(const Ticket&);
    virtual ~Ticket();
    
    double getPrice() const;
    const char* getNameOfPerformance() const;
    
    void setPrice(double);
    
    virtual void print() const;
    virtual int howManySpectators() const;
private:
    char* nameOfPerformance;
    double price;
    
    void copyTicket(const Ticket&);
};
#endif /* Ticket_hpp */
