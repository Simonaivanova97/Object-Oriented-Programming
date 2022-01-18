#include <iostream>
#include "ElectricDevice.hpp"
#include "ElectricNet.hpp"
using namespace std;

int main() {

    ElectricDevice e1("tv", 50);
    ElectricDevice e2("laptop", 20);
    ElectricDevice e3("washing machine", 70);
    ElectricDevice e4("fridge", 60);
    ElectricDevice e5("oven", 80);

    ElectricNet net1(220);
    net1+=e1;
    net1+=e2;
    net1+=e3;
    net1+=e4;
    net1.print();
    cout<<"\n--------------------\n";
    
    cout<<"----- Add oven -----"<<endl;
    net1+=e5;
    cout<<"\n--------------------\n";

    cout<<"----- Remove fridge and tv -----"<<endl;
    net1-=("fridge");
    net1-=("tv");
    net1.print();
    cout<<"\n--------------------\n";
    
    net1["PC"].print();
    cout<<"\n--------------------\n";
    
    cout<<"----- ElectricNet = ElectricNet -----"<<endl;
    ElectricNet net2=net1;
    net2.print();
    return 0;
}
