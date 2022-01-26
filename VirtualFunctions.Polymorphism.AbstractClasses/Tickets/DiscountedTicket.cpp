#include "DiscountedTicket.hpp"
DiscountedTicket::DiscountedTicket(const char* pN, double p) : Ticket(pN,p){
    setPrice(p/2);
}
DiscountedTicket::~DiscountedTicket(){}
void DiscountedTicket::print() const{
    cout<<"---------- Discounted ticket ----------"<<endl;
    cout<<"Name of the performance: "<<getNameOfPerformance()<<endl;
    cout<<"Price: "<<getPrice()<<endl;
}
