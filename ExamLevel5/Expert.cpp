#include "Expert.hpp"
Expert::Expert() : Employee() {}
Expert::Expert(const char* n, int nT, int sT) : Employee(n, nT, sT) {}
Expert::~Expert(){}
bool Expert::execute(const char* task){
    numberOfExecuteTasks++;
    successfullyCompletedTasks++;
    return true;
}
double Expert::successRate() const{
    if(numberOfExecuteTasks==0){
        return 0;
    }
    return (double)successfullyCompletedTasks/numberOfExecuteTasks;
}
Employee* Expert::clone(){
    return new Expert(*this);
}
void Expert::print() const{
    cout<<*this<<endl;
}
ostream& operator<<(ostream& out, const Expert& e){
    out<<"expert: "<<e.getName();
    return out;
}
