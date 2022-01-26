#include <iostream>
#include "Device.hpp"
#include "Laptop.hpp"
#include "Car.hpp"
#include "Inventory.hpp"
using namespace std;

int main() {
    Car toyoata("toyota", 5, 20);
    Laptop toshiba("toshiba",40);
    
    Device* arr[2]={&toyoata, &toshiba};
    Inventory inv(arr,2,100);
    inv.print();
    cout<<endl;
    
    cout<<inv.inAscendingOrder()<<endl;
    return 0;
}


