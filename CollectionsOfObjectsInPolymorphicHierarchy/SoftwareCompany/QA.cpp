#include "QA.hpp"
QA::QA() : ITSpecialist(){
    type=TypeQa::autumation;
}
QA::QA(const char* n, int e, double s, const char* pN, TypeQa t) : ITSpecialist(n, e, s, pN){
    type=t;
}
QA::~QA(){}
void QA::print() const{
    ITSpecialist::print();
    cout<<"QA type: "<<types[static_cast<int>(type)]<<endl;
}
Employee* QA::clone(){
    return new QA(*this);
}
