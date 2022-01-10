//
//  Group.cpp
//  HW2
//
//  Created by Simona Ivanova on 7.06.20.
//  Copyright © 2020 Simona Ivanova. All rights reserved.
//

#include "Group.hpp"
#include <iostream>
using namespace std;
Group::Group(const char* n,unsigned int gId):Institution(n){
    groupId=gId;
    groupPayer=nullptr;
}
Group::Group(const char* n,unsigned int gId, Payer& p):Institution(n){
    groupId=gId;
    groupPayer=&p;
}

bool Group::valid() const{
    if(groupPayer!=nullptr){
        return true;
    }
    else{
        return false;
    }
}
bool Group::hasMember(const Person& p) const{
    if(groupPayer!=nullptr){
        if(groupPayer->takeResult(groupId,p.getInsuranceId())){
            return true;
        }
        else{
            return false;
        }
    }
    else{
        return false;
    }
}
void Group::print() const{
    cout<<"This institution has id: "<<getId()<<". The groupId is: "<<groupId<<"."<<endl;
    if (groupPayer!=nullptr){
        groupPayer->print();
    }
    else{
        cout<<"The group don't have payer."<<endl;
    }
}

Payer* Group::getPayer() const{
    return groupPayer;
}
