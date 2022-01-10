//
//  Employee.cpp
//  Date
//
//  Created by Simona Ivanova on 12.09.21.
//

#include "Employee.hpp"

bool Employee::validSalary(double s) const{
    if(s>610 && s<4500){
        return true;
    }
    else{
        return false;
    }
}

Employee::Employee(){
    strcpy(name, "Unknown");
    name[maxName]='\0';
    dateОfАppointment=Date();
    strcpy(position, "Unknown");
    position[maxPosition]='\0';
    salary=610;
}

Employee::Employee(const char* n, const Date& d, const char* p, double s){
    strcpy(name, n);
    name[maxName]='\0';
    dateОfАppointment=d;
    strcpy(position, p);
    position[maxPosition]='\0';
    if(validSalary(s)){
        salary=s;
    }
    else{
        salary=611;
    }
}

const char* Employee::getName()const{
    return name;
}
Date Employee::getDate()const{
    return dateОfАppointment;
}
const char* Employee::getPosition()const{
    return position;
}
double Employee::getSalary()const{
    return salary;
}

void Employee::setName(const char* n){
    strncpy(name, n,maxName-1);
    name[maxName-1]='\0';
}
void Employee::setDate(const Date& d){
    dateОfАppointment=d;
}
void Employee::setPosition(const char* p){
    strncpy(position, p,maxPosition-1);
    position[maxPosition-1]='\0';
}
void Employee::setSalary(double s){
    if(validSalary(s)){
        salary=s;
    }
}

void Employee::print() const{
    //cout<<"--- Information about employee. ---"<<endl;
    cout<<"Name: "<<name<<endl;
    dateОfАppointment.print();
    cout<<"Position: "<<position<<endl;
    cout<<"Salary: "<<salary<<endl;
}
