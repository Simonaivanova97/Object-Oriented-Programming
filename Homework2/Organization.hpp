//
//  Organization.hpp
//  HW2
//
//  Created by Simona Ivanova on 7.06.20.
//  Copyright © 2020 Simona Ivanova. All rights reserved.
//

#ifndef Organization_hpp
#define Organization_hpp

#include <stdio.h>
#include"Payer.hpp"
#include"Person.hpp"
#include"Institution.hpp"
#include<vector>
using namespace std;
class Organization:public Institution{
public:
    Organization(const char*,vector<Institution*>,const char*);
    Organization(const Organization&);
    Organization& operator=(const Organization&);
    ~Organization();
    
    virtual bool valid() const override;
    virtual bool hasMember(const Person&) const override;
    virtual Payer* getPayer() const override;
    virtual void print()const override;
    
    bool isCompatible(const Institution&) const;
    void add_institution(Institution&);
private:
    vector<Institution*> arr;
    char* organization_address;
    
    void doCopy(vector<Institution*>,const char*);
};
#endif /* Organization_hpp */
