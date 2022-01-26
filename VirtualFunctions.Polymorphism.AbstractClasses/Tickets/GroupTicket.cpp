#include "GroupTicket.hpp"
GroupTicket::GroupTicket(const char* pN, double p, int n) : Ticket(pN, p){
    numberSpectators=n;
    if(n>=20){
        setPrice(getPrice()-2);
    }
    if(getPrice()<0){
        setPrice(0);
    }
}
GroupTicket::~GroupTicket(){}
void GroupTicket::print() const{
    if(numberSpectators>=20){
        cout<<"---------- Group ticket ----------"<<endl;
        cout<<"Name of the performance: "<<getNameOfPerformance()<<endl;
        cout<<"Price for one spectators: "<<getPrice()<<endl;
    }
    else{
        Ticket::print();
    }
}
int GroupTicket::howManySpectators() const{
    return numberSpectators;
}
