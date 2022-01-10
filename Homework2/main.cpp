//
//  main.cpp
//  HW2
//
//  Created by Simona Ivanova on 7.06.20.
//  Copyright © 2020 Simona Ivanova. All rights reserved.
//

#include <iostream>
#include"Payer.hpp"
#include"Person.hpp"
#include "Institution.hpp"
#include"Organization.hpp"
#include"Group.hpp"
using namespace std;
vector<Institution*> clear_institution(vector<Institution*> arr){
    vector<Institution*> result;
    for (int i=0;i<arr.size();i++){
        if(arr[i]->valid()){
            result.push_back(arr[i]);
        }
    }
    return result;
}

Institution* find_mostpopular_institutuion(vector<Institution*> arr,vector<Person> arrPerson){
    for (int i=0;i<arr.size()-1;i++){
        int count=0;
        for (int j=0;j<arrPerson.size();j++){
            if (arr[i]->hasMember(arrPerson[j])){
                count++;
            }
        }
        cout<<"Institution has "<<count<<" persons"<<endl;
    }
    return arr[0];
}
bool member_func(int group_id, int insurance_id){
    return (group_id+insurance_id)%2==0;
}

int main() {
    bool (*ptr)(int,int){member_func};
    Payer p1("alianz",ptr);
    Payer p2("bulstrat",ptr);
    
    Person firstPerson("Petur",5);
    Person secondPerson("Stoqn",5);
    Person thirthPerson("Tanq",5);
    
    Group g("Purva instituciq",7,p1);
    Group g1("Vtora instituciq",7,p1);
    Group g2("Treta instituciq",8,p2);
    Group g3("Chetvurta instituciq",8,p1);
    
    vector<Institution*> arr;
    arr.push_back(&g);
    arr.push_back(&g1);
    arr.push_back(&g2);
    //arr.push_back(&g3);
    
    Organization o1("Peta instituciq",arr,"Purvi adres");
    cout<<"Payer of Peta instituciq: "<<o1.getPayer()->getName()<<endl;
    cout<<"Uniq id for Peta organizaciq: "<<o1.getId()<<endl;
    vector<Institution*> otherArr;
    Institution* in2=&o1;
    Institution* in3=&g3;
    otherArr.push_back(in3);
    otherArr.push_back(in2);
    Organization o2("Shesta instituciq",otherArr,"Vtori adress");
    Organization o4=o2;
    vector<Institution*> arr1;
    Organization o3("Sedma instituciq",arr1,"Treti adres");
    o2.add_institution(o3);
    
    
    //find_mostpopular_institutuion({&o2,&o1,&g,&g1,&g2}, {firstPerson,secondPerson,thirthPerson});
    
    return 0;
}
