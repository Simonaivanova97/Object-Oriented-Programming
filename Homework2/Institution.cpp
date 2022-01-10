//
//  Institution.cpp
//  HW2
//
//  Created by Simona Ivanova on 7.06.20.
//  Copyright © 2020 Simona Ivanova. All rights reserved.
//

#include "Institution.hpp"
#include<iostream>
#include<string>
int Institution::count=0;
int Institution::nexId=0;
int Institution::generateId(){
    return ++nexId;
}
Institution::Institution(){
    ++count;
    id=Institution::generateId();
}
Institution::Institution(const char* n){
    name=new char[strlen(n)+1];
    strcpy(name,n);
    ++count;
    id=Institution::generateId();
}
Institution::Institution(const Institution& other){
    id=Institution::generateId();
    ++count;
    name=new char[strlen(other.name)+1];
    strcpy(name,other.name);
}
Institution& Institution::operator=(const Institution& other){
    if(this!=&other){
        delete[]name;
        id=Institution::generateId();
        ++count;
        name=new char[strlen(other.name)+1];
        strcpy(name,other.name);
    }
    return *this;
}
Institution::~Institution(){
    --count;
}
int Institution::getId() const{
    return id;
}
int Institution::getCount(){
    return count;
}
