//
//  Group.hpp
//  HW2
//
//  Created by Simona Ivanova on 7.06.20.
//  Copyright © 2020 Simona Ivanova. All rights reserved.
//

#ifndef Group_hpp
#define Group_hpp
#include <stdio.h>
#include"Payer.hpp"
#include"Person.hpp"
#include"Institution.hpp"
class Group:public Institution{
public:
    Group(const char*,unsigned int);
    Group(const char*,unsigned int,Payer&);
    
    virtual bool valid() const override;
    virtual bool hasMember(const Person&) const override;
    virtual Payer* getPayer() const override;
    virtual void print() const override;
private:
    unsigned int groupId;
    Payer* groupPayer;
};
#endif /* Group_hpp */
