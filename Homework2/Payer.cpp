//
//  Payer.cpp
//  HW2
//
//  Created by Simona Ivanova on 7.06.20.
//  Copyright © 2020 Simona Ivanova. All rights reserved.
//

#include "Payer.hpp"
#include<iostream>
using namespace std;

Payer::Payer(const char* newPayerName,bool (*func)(int,int)){
    payer_member_rule=func;
    payer_name=new char[strlen(newPayerName)+1];
    strcpy(payer_name,newPayerName);
}
bool Payer::takeResult(int n,int m){
    return (*payer_member_rule)(n,m);
}
void Payer::print()const{
    cout<<"Name of payer: "<<payer_name<<endl;
}
const char* Payer::getName() const{
    return payer_name;
}
