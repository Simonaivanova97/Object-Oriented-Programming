#include <iostream>
#include "Doctor.hpp"
#include "Nurse.hpp"
#include "Dentist.hpp"
#include "Surgeon.hpp"
#include "Hospital.hpp"
using namespace std;

int main() {

    Doctor* arr[3];
    arr[0]=new Nurse("Petya Petrova", 3, 67);
    arr[1]=new Dentist("Delyan Zlatev", 26, 128);
    arr[2]=new Surgeon("Petar Kinov", 50, 234, 234, "Orthopedic surgeons", 134);
    
    Hospital h(2);
    for(int i=0;i<3;i++){
        h.addDoctor(arr[i]);
    }
    
    h.print();
    cout<<endl;
    //h.removeDoctor(320);
    //h.print();
    
    //h.removeDentist(120);
    //h.print();
    
    //h.removeSurgeon(140);
    //h.print();
    
    //h.removeNurse(70);
    //h.print();
    
    delete arr[0], arr[1], arr[2];
    return 0;
}

