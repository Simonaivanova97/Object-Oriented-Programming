#ifndef DiscountedTicket_hpp
#define DiscountedTicket_hpp

#include <stdio.h>
#include "Ticket.hpp"

class DiscountedTicket : public Ticket{
public:
    DiscountedTicket(const char*, double);
    virtual ~DiscountedTicket();
    
    virtual void print() const override;
};
#endif /* DiscountedTicket_hpp */
