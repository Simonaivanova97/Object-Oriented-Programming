#include <iostream>
#include "Doctor.hpp"
#include "Surgeon.hpp"
#include "Vet.hpp"
using namespace std;

int main() {
    Doctor drNikolov("Ivan Nikolov", 12);
    cout<<drNikolov;
    cout<<"\n--------------------\n";
    
    Surgeon drPetrova("Mariya Petrova", 15, "vascular surgery");
    cout<<drPetrova;
    cout<<"Chance for a successful operation in the direction - vascular surgery: "<<drPetrova.chance("vascular surgery")<<endl;
    cout<<"Chance for a successful operation in the direction - general surgery: "<<drPetrova.chance("general surgery")<<endl;
    cout<<"\n--------------------\n";
    
    Vet drIvanov("Miroslav Ivanov", 5, "cow");
    cout<<drIvanov;
    
    return 0;
}
