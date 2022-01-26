#include "Magazine.hpp"
Magazine::Magazine() : PrintEdition(){
    period=Periodicity::Weekly;
}
Magazine::Magazine(const char* t, int y, double p, Periodicity per) : PrintEdition(t, y, p){
    period=per;
}
void Magazine::print() const{
    PrintEdition::print();
    cout<<"The magazine has periodicity: "<<periodicities[static_cast<int>(period)]<<endl;
}
void Magazine::printOwlyPeriodicity() const{
    cout<<"The magazine has periodicity: "<<periodicities[static_cast<int>(period)]<<endl;
}
