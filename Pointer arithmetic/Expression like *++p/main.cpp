//
//  main.cpp
//  Pointer arithmetic
//
//  Created by Simona Ivanova on 10.09.23.
//

#include <iostream>
using namespace std;

int main(){
    char str [] = "Simona";
    char* p = str;
    while(*p) {
        cout<< "Before = " << *p <<endl;
        cout<< *++p <<endl;
        cout<< "----------" <<endl;
    }
    return 0;
}
