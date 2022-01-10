//
//  Institution.hpp
//  HW2
//
//  Created by Simona Ivanova on 7.06.20.
//  Copyright © 2020 Simona Ivanova. All rights reserved.
//

#ifndef Institution_hpp
#define Institution_hpp

#include <stdio.h>
#include "Person.hpp"
#include "Payer.hpp"
class Institution{
public:
    Institution();
    Institution(const char*);
    Institution(const Institution&);
    Institution& operator=(const Institution&);
    virtual ~Institution();

    int getId() const;
    static int getCount();
    
    virtual bool valid()const=0;
    virtual bool hasMember(const Person&) const=0;
    virtual Payer* getPayer() const=0;
    virtual void print() const=0;
    
private:
    char* name;
    static int count;
    int id;
    static int nexId;
    static int generateId();
    };

#endif /* Institution_hpp */
