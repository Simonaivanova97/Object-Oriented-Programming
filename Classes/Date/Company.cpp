//
//  Company.cpp
//  Date
//
//  Created by Simona Ivanova on 12.09.21.
//

#include "Company.hpp"

bool Company::hasThisEmployee(const char* name){
    bool has=false;
    if(currentNumberEmployee>0){
        for(int i=0;i<currentNumberEmployee;i++){
            if(strcmp(arr[i].getName(), name)==0){
                has=true;
            }
        }
    }
    return has;
}

Company::Company(){
    currentNumberEmployee=0;
    strncpy(companyName, "First Company", maxCompanyName-1);
    companyName[maxCompanyName-1]='\0';
}

void Company::appointsNewEmployee(const Employee& e){
    if(currentNumberEmployee<=150){
        arr[currentNumberEmployee]=e;
        currentNumberEmployee++;
    }
    else{
        cout<<"The company does not hire employees!"<<endl;
    }
}
void Company::laysOffEmployee(const char* n){
    if(hasThisEmployee(n)){
        bool indexAfterName=false;
        for(int i=0;i<currentNumberEmployee-1;i++){
            if(strcmp(arr[i].getName(),n)==0){
                indexAfterName=true;
            }
            if(indexAfterName){
                arr[i]=arr[i+1];
            }
        }
        currentNumberEmployee--;
    }
}
void Company::print()const{
    cout<<"--- Information about company - "<<companyName<<". ---"<<endl;
    cout<<"\nCurrent number of employers: "<<currentNumberEmployee<<endl;
    if(currentNumberEmployee>0){
        cout<<"----------Employers in company----------"<<endl;
        for(int i=0;i<currentNumberEmployee;i++){
            cout<<"\nEmployee "<<i+1<<endl;
            arr[i].print();
        }
    }
}

double Company::budget()const{
    double sum=0;
    for(int i=0;i<currentNumberEmployee;i++){
        sum+=arr[i].getSalary();
    }
    return sum;
}
void Company::increasesSalaries(){
    for(int i=0;i<currentNumberEmployee;i++){
        double tempSalary=arr[i].getSalary()*0.1+arr[i].getSalary();
        arr[i].setSalary(tempSalary);
    }
}
