//
//  main.cpp
//  Date
//
//  Created by Simona Ivanova on 12.09.21.
//
#include <iostream>
#include "Date.hpp"
#include "Employee.hpp"
#include "Company.hpp"

int main() {
    /*Date d(13,9,2021);
    Date other(12,9,2021);
    d.print();
    if(d.isDateBefore(other)){
        cout<<"\nYes!"<<endl;
        d.print();
        cout<<"is before"<<endl;
        other.print();
    }
    else{
        cout<<"\nNo!"<<endl;
        d.print();
        cout<<"is NOT before"<<endl;
        other.print();
    }*/
    Date d1(13,9,2021);
    Date d2(4,3,2021);
    Date d3(18,2,2021);
    Date d4(10,1,2020);
    Date d5(14,2,2020);
    Date d6(25,11,2021);
    Employee e1("Petya", d1,"P1",700);
    Employee e2("Atanas", d2,"P2",900);
    Employee e3("Dimitar", d3,"P3",1000);
    Employee e4("Yana", d4,"P4",876.98);
    Employee e5("Miroslav", d3,"P5",984.76);
    Employee e6("Iva", d5,"P3",3007.98);
    
    Company c;
    c.appointsNewEmployee(e1);
    c.appointsNewEmployee(e2);
    c.appointsNewEmployee(e3);
    c.appointsNewEmployee(e4);
    c.appointsNewEmployee(e5);
    c.appointsNewEmployee(e6);
    c.print();
    
    cout<<"\nAFTER LAYS OFF Atanas"<<endl;
    c.laysOffEmployee("Atanas");
    c.print();
    
    cout<<"\nBudget of company >= "<<c.budget()<<endl;
    cout<<"\n--- Afret increase salary. ---"<<endl;
    c.increasesSalaries();
    c.print();
    return 0;
}
