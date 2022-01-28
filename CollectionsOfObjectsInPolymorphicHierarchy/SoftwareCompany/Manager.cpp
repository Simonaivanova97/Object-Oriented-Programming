#include "Manager.hpp"
Manager::Manager() : Employee(){
    numberOfSubordinates=0;
}
Manager::Manager(const char* n, int e, double s, int nS) : Employee(n, e, s){
    numberOfSubordinates=nS;
}
Manager::~Manager(){}
void Manager::print() const{
    Employee::print();
    cout<<"Number of subordinates: "<<numberOfSubordinates<<endl;
}
Employee* Manager::clone(){
    return new Manager(*this);
}
