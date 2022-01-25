#ifndef GroupTicket_hpp
#define GroupTicket_hpp

#include <stdio.h>
#include "Ticket.hpp"

class GroupTicket : public Ticket{
public:
    GroupTicket(const char*, double, int);
    virtual ~GroupTicket();
    
    virtual void print() const override;
    virtual int howManySpectators() const override;
private:
    int numberSpectators;
};

#endif /* GroupTicket_hpp */
