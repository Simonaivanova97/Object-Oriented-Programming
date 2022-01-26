#include "Inventory.hpp"
void Inventory::copyInventory(const Inventory& other){
    numberOfDevices=other.numberOfDevices;
    maxCapacity=other.maxCapacity;
    arr=new Device*[maxCapacity];
    assert(arr!=NULL);
    for(int i=0;i<numberOfDevices;i++){
        arr[i]=other.arr[i]->clone();
    }
}
void Inventory::erase(){
    for(int i=0;i<numberOfDevices;i++){
        delete arr[i];
    }
    delete []arr;
}
Inventory::Inventory(){
    numberOfDevices=0;
    maxCapacity=0;
    arr=NULL;
}
Inventory::Inventory(Device** a, int nD, int mC){
    maxCapacity=mC;
    numberOfDevices=nD;
    arr=new Device*[maxCapacity];
    assert(arr!=NULL);
    for(int i=0;i<numberOfDevices;i++){
        arr[i]=a[i]->clone();
    }
}
Inventory::Inventory(const Inventory& other){
    copyInventory(other);
}
Inventory& Inventory::operator=(const Inventory& other){
    if(this!=&other){
        erase();
        copyInventory(other);
    }
    return *this;
}
Inventory::~Inventory(){
    erase();
}

void Inventory::print() const{
    cout<<"Number of devices: "<<numberOfDevices<<endl;
    for(int i=0;i<numberOfDevices;i++){
        arr[i]->print();
    }
}
bool Inventory::inAscendingOrder() const{
    for(int i=0;i<numberOfDevices-1;i++){
        if(arr[i]->get_perf()>arr[i+1]->get_perf()){
            return false;
        }
    }
    return true;
}

