#include "Ticket.hpp"
void Ticket::copyTicket(const Ticket& other){
    nameOfPerformance=new char[strlen(other.nameOfPerformance)+1];
    assert(nameOfPerformance!=NULL);
    strcpy(nameOfPerformance, other.nameOfPerformance);
    price=other.price;
}
Ticket::Ticket(){
    nameOfPerformance=new char[strlen("Unknown")+1];
    assert(nameOfPerformance!=NULL);
    strcpy(nameOfPerformance, "Unknown");
    price=0;
}
Ticket::Ticket(const char* nP, double p){
    nameOfPerformance=new char[strlen(nP)+1];
    assert(nameOfPerformance!=NULL);
    strcpy(nameOfPerformance, nP);
    price=p;
}
Ticket::Ticket(const Ticket& other){
    copyTicket(other);
}
Ticket& Ticket::operator=(const Ticket& other){
    if(this!=&other){
        delete []nameOfPerformance;
        copyTicket(other);
    }
    return *this;
}
Ticket::~Ticket(){
    delete []nameOfPerformance;
}
double Ticket::getPrice() const{
    return price;
}
const char* Ticket::getNameOfPerformance() const{
    return nameOfPerformance;
}
void Ticket::setPrice(double p){
    price=p;
}
void Ticket::print() const{
    cout<<"---------- Normal ticket ----------"<<endl;
    cout<<"Name of the performance: "<<nameOfPerformance<<endl;
    cout<<"Price: "<<price<<endl;
}
int Ticket::howManySpectators() const{
    return 1;
}

