//
//  Organization.cpp
//  HW2
//
//  Created by Simona Ivanova on 7.06.20.
//  Copyright © 2020 Simona Ivanova. All rights reserved.
//

#include "Organization.hpp"
void Organization::doCopy(vector<Institution*> a,const char* orgAddress){
    for (int i=0;i<a.size();i++){
        arr.push_back(a[i]);
    }
    organization_address=new char[strlen(orgAddress)+1];
    strcpy(organization_address,orgAddress);
}
Organization::Organization(const char* n,vector<Institution*> a,const char* orgAddress):Institution(n){
    doCopy(a, orgAddress);
}
Organization::Organization(const Organization& other):Institution(other){
    doCopy(other.arr, other.organization_address);
}
Organization& Organization::operator=(const Organization& other){
    if(this!=&other){
        Institution::operator=(other);
        
        delete []organization_address;
        doCopy(other.arr, other.organization_address);
    }
    return *this;
}
Organization::~Organization(){
    delete []organization_address;
}
bool Organization::valid() const{
    if(!arr.empty()){
        return true;
    }
    else{
        return false;
    }
}
bool Organization::hasMember(const Person& p)const{
    bool isMember=false;
    for (int i=0;i<arr.size();i++){
        if(arr[i]->hasMember(p)){
            isMember=true;
        }
    }
    return isMember;
}
Payer* Organization::getPayer() const{
    vector<Payer*> onlyPayer;
    for (int i=0;i<arr.size();i++){
        if(arr[i]->getPayer()!=nullptr){
            onlyPayer.push_back(arr[i]->getPayer());
        }
    }
    if(onlyPayer.empty()){
        return nullptr;
    }
    else{
        int count=0,curr_count=1;
        Payer* feq_payer=nullptr,*key=nullptr;
        for (int i =0;i<onlyPayer.size()-1;i++){
            key=onlyPayer[i];
            for (int j=i+1;j<onlyPayer.size();j++){
                if(key==onlyPayer[j]&& feq_payer!=key){
                    curr_count++;
                }
            }
            if(count<curr_count){
                count=curr_count;
                curr_count=1;
                feq_payer=key;
            }
        }
        return feq_payer;
    }
}
void Organization::print() const{
    for (int i=0;i<arr.size();i++){
        arr[i]->print();
    }
}
bool Organization::isCompatible(const Institution& other)const{
    if(getPayer()==other.getPayer()){
        return true;
    }
    else{
        return false;
    }
}
void Organization::add_institution(Institution& other){
    bool rule;
    if(other.valid() && isCompatible(other)){
        rule=true;
    }
    else{
        rule=false;
    }
    if(rule){
        arr.push_back(&other);
    }
    else{
        char answer[4];
        cout<<"Do you want to ignore the rule?"<<endl;
        do{
            cout<<"Yes or No"<<endl;
            cin>>answer;
            answer[strlen(answer)]='\0';
        }while(strcmp(answer,"Yes")  && strcmp(answer,"No"));
        if(!strcmp(answer,"Yes")){
            arr.push_back(&other);
        }
        else{
            cout<<"No changes!"<<endl;
        }
    }
}
