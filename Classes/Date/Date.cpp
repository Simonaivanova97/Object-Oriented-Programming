//
//  Date.cpp
//  Date
//
//  Created by Simona Ivanova on 12.09.21.
//

#include "Date.hpp"

bool Date::leapYear(const int& y) const{
if(y%4==0) {
        if(y%100==0) {
            if(y%400==0){
                return true;
            }
            else{
                return false;
            }
        }
        else{
            return true;
        }
    }
else{
    return false;
}
}

bool Date::validDate(const int& d,const int& m,const int& y){
bool valid;
if(y>0){
    if(leapYear(y)){
        if(m>=1 && m<=12){
            if(m==2){
                if(d>=1 && d<=29){
                    valid=true;
                }
                else{
                    valid=false;
                }
            }
            else if (m==1 || m==3 || m==5 || m==7 || m==8 || m==10 || m==12){
                if(d>=1 && d<=31){
                    valid=true;
                }
                else{
                    valid=false;
                }
            }
            else if(m==4 || m==6 || m==9 || m==11){
                if(d>=1 && d<=30){
                    valid=true;
                }
                else{
                    valid=false;
                }
            }
        }
        else{
            valid=false;
        }
    }
    else{
        if(m>=1 && m<=12){
            if(m==2){
                if(d>=1 && d<=28){
                    valid=true;
                }
                else{
                    valid=false;
                }
            }
            else if (m==1 || m==3 || m==5 || m==7 || m==8 || m==10 || m==12){
                if(d>=1 && d<=31){
                    valid=true;
                }
                else{
                    valid=false;
                }
            }
            else if(m==4 || m==6 || m==9 || m==11){
                if(d>=1 && d<=30){
                    valid=true;
                }
                else{
                    valid=false;
                }
            }
        }
        else{
            valid=false;
        }
    }
}
else{
    valid=false;
}
return valid;
}

Date::Date(){
    day=1;
    month=1;
    year=2000;
}

Date::Date(int d,int m,int y){
    if(validDate(d, m, y)){
        day=d;
        month=m;
        year=y;
    }
    else{
        cerr<<"Invalid date!"<<endl;
    }
}

int Date::getDay()const{
    return day;
}

int Date::getMonth()const{
    return month;
}

int Date::getYear()const{
    return year;
}

void Date::setDay(int d){
    if(validDate(d, month, year)){
        day=d;
    }
    else{
        cerr<<"Invalid date!"<<endl;
    }
}

void Date::setMonth(int m){
    if(validDate(day, m, year)){
        month=m;
    }
    else{
        cerr<<"Invalid date!"<<endl;
    }
}

void Date::setYear(int y){
    if(validDate(day, month, y)){
        year=y;
    }
    else{
        cerr<<"Invalid date!"<<endl;
    }
}

void Date::print()const{
    cout<<"Print date like: day - month - year"<<endl;
    if(day<10){
        cout<<"0";
    }
    cout<<day<<" - ";
    if(month<10){
        cout<<"0";
    }
    cout<<month<<" - "<<year<<endl;
}

bool Date::isDateBefore(const Date& other){
    bool before;
    if(year<other.getYear()){
        before=true;
    }
    else if(year==other.getYear()){
        if(month<other.getMonth()){
            before=true;
        }
        else if(month==other.getMonth()){
            if(day<other.getDay()){
                before=true;
            }
            else{
                before=false;
            }
        }
    }
    return before;
}

