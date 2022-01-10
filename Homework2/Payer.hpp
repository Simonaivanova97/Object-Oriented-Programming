//
//  Payer.hpp
//  HW2
//
//  Created by Simona Ivanova on 7.06.20.
//  Copyright © 2020 Simona Ivanova. All rights reserved.
//

#ifndef Payer_hpp
#define Payer_hpp

#include <stdio.h>
class Payer{
public:
    Payer(const char*,bool (*ptr)(int,int));
    //Тъй като по условие, застрахователите не могат да се копират, това значи, че трябва да не дефинираме копиращ конструктор и операция за присвояване, и трбява да забраним създаване на системни такива.
    Payer(const Payer& other)=delete;
    Payer& operator=(const Payer& other)=delete;
    
    bool takeResult(int n, int m);
    void print() const;
    const char* getName() const;
private:
    char* payer_name;
    bool (*payer_member_rule)(int, int);
};
#endif /* Payer_hpp */
