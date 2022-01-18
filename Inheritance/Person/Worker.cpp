#include "Worker.hpp"
Worker::Worker() : Person(){
    salaryForHour=0;
    hours=0;
}
Worker::Worker(const char* fN, const char* lN, int a, double sH, int h) : Person(fN, lN, a){
    salaryForHour=sH;
    hours=h;
}
void Worker::print() const{
    Person::print();
    cout<<"Salary: "<<calculateSalary()<<endl;
}
double Worker::calculateSalary() const{
    return hours*salaryForHour;
}
