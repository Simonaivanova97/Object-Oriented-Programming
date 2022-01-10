//
//  Person.cpp
//  HW2
//
//  Created by Simona Ivanova on 7.06.20.
//  Copyright © 2020 Simona Ivanova. All rights reserved.
//

#include "Person.hpp"
#include<iostream>
using namespace std;
void Person::doCopy(const char* newPersonName,int newInsuranceId){
    person_name=new char[strlen(newPersonName)+1];
    strcpy(person_name,newPersonName);
    insurance_id=newInsuranceId;
}
Person::Person(){
    doCopy("", 0);
}
Person::Person(const char* newPersonName, int newInsuranceId){
    doCopy(newPersonName, newInsuranceId);
}
Person::Person(const Person& other){
    doCopy(other.person_name, other.insurance_id);
}
Person& Person::operator=(const Person& other){
    if(this!=&other){
        delete []person_name;
        doCopy(other.person_name, other.insurance_id);
    }
    return *this;
}
Person::~Person(){
    delete []person_name;
}
   
const char* Person::getPersonName()const{
    return person_name;
}
int Person::getInsuranceId() const{
    return insurance_id;
}
   
void Person::setPersonName(const char* newPersonName){
    delete []person_name;
    person_name=new char[strlen(person_name)+1];
    strcpy(person_name,newPersonName);
}
void Person::setInsuranceId(int newInsuranceId){
    insurance_id=newInsuranceId;
}
