//
//  Date.hpp
//  Date
//
//  Created by Simona Ivanova on 12.09.21.
//

#ifndef Date_hpp
#define Date_hpp

#include <stdio.h>
#include <iostream>
using namespace std;

class Date{
public:
    Date();
    Date(int, int, int);
    
    int getDay()const;
    int getMonth()const;
    int getYear()const;
    
    void setDay(int);
    void setMonth(int);
    void setYear(int);
    
    void print()const;
    
    bool isDateBefore(const Date&);
private:
    int day,month,year;
    
    bool leapYear(const int& y) const;
    bool validDate(const int& d,const int& m,const int& y);
};
#endif /* Date_hpp */
